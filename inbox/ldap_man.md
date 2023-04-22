Integrate OpenLDAP or Windows AD with SkyForm AIP
=====================================
If you use OpenLDAP
    if you have an existing OpenLDAP server, please refer to:
        2. Configure OpenLDAP Client
        5. Run cbtool command
        6. Run aip command
    if you don't have an OpenLDAP server, please refer to:
        1. Install and Configure OpenLDAP Server
        2. Configure OpenLDAP Client
        5. Run cbtool command
        6. Run aip command
If you use Windows AD
    if you have an existing AD server, please refer to:
        4. Configure AD Client
        5. Run cbtool command
        6. Run aip command
    if you don't have an AD server, please refer to:
        3. Install and Configure AD Server
        4. Configure AD Client
        5. Run cbtool command
        6. Run aip command


1. Install and Configure OpenLDAP Server
=====================================

Skip this step if have an existing LDAP server.

(1) Install OpenLDAP packages
# yum -y install openldap compat-openldap openldap-clients openldap-servers openldap-servers-sql openldap-devel

(2) Start service
# systemctl start slapd
# systemctl enable slapd

(3) Verify LDAP
# netstat -antup | grep -i 389
tcp        0      0 0.0.0.0:389             0.0.0.0:*               LISTEN      2601/slapd
tcp6       0      0 :::389                  :::*                    LISTEN      2601/slapd

(4) Setup LDAP admin password (specify -s with your own password)
#slappasswd -h {SSHA} -s password
{SSHA}SIxzVXtWEXZg09CxdK0Yy2nnJmTbQFeV

Replace the encrypted password of "olcRootPW" section in file "chrootpw.ldif" and "db.ldif" with the password generated above.

#ldapadd -Y EXTERNAL -H ldapi:/// -f chrootpw.ldif

(5) Import basic Schemas
# ldapadd -Y EXTERNAL -H ldapi:/// -f /etc/openldap/schema/cosine.ldif
# ldapadd -Y EXTERNAL -H ldapi:/// -f /etc/openldap/schema/nis.ldif
# ldapadd -Y EXTERNAL -H ldapi:/// -f /etc/openldap/schema/inetorgperson.ldif

(6) Configure OpenLDAP server
#ldapmodify -Y EXTERNAL  -H ldapi:/// -f db.ldif

(7) Setup LDAP database
#ldapadd -x -W -D "cn=ldapadm,dc=skycloud,dc=com" -f base.ldif

(8) Validate the new attribute values
# ldapsearch -Y EXTERNAL -H ldapi:/// -b cn=config olcDatabase=\*


2. Configure OpenLDAP Client
=====================================

You need configure OpenLDAP client on all SkyCloud AIP hosts (Step 1 to 6).

(1) Install SSSD
# # yum install sssd sssd-client

(2) Configure NSS and PAM; will generate  /etc/sssd/sssd.conf
# authconfig  --enableldap --enableldapauth --ldapserver="ldapserver.skycloud.com" --ldapbasedn="dc=skycloud,dc=com" --update

(3) Configure SSSD. Replace or add following fields in file /etc/sssd/sssd.conf
#tls is not required for id_provider connection
ldap_id_use_start_tls = False
#Every user that can authenticate is given permission to login to the system
access_provider = permit
#The client will not request or check any server certificate
ldap_tls_reqcert = never
#Use short name for logon
use_fully_qualified_names = False

(4) Set the permissions
# chown root:root /etc/sssd/sssd.conf
# chmod 600 /etc/sssd/sssd.conf

(5) Enable and Start SSSD
# systemctl enable sssd
# systemctl start sssd

(6) Configure for creating home directoryautomatically when first timelogin:
Edit /etc/pam.d/sshd, add a line: 
session    required     pam_mkhomedir.so 

(7) Test your configuration. Make sure you can create a user and login.
# ldapadd -x -W -D "cn=ldapadm,dc=skycloud,dc=com" -f testuser.ldif
Enter LDAP Password:
adding new entry "cn=testuser,ou=People,dc=skycloud,dc=com"
# id testuser
uid=2001(testuser) gid=2001 groups=2001
# su testuser
Password:
[testuser@node1 ldap]$ 

(8) Add aip admin accout (cadmin by default) to ldap:
#ldapadd -x -W -D "cn=ldapadm,dc=skycloud,dc=com" -f cadmin.ldif
Enter LDAP Password: 
adding new entry "uid=cadmin,ou=People,dc=skycloud,dc=com"

# ldapadd -x -W -D "cn=ldapadm,dc=skycloud,dc=com" -f cadmingroup.ldif
Enter LDAP Password: 
adding new entry "cn=cadmin,ou=Group,dc=skycloud,dc=com"

# id cadmin
uid=1010(cadmin) gid=1010(cadmin) groups=1010(cadmin)

3. Install and Configure AD Server
=====================================
Refer to Microsoft documents to install AD domain services and certification authority.
Certification authority is required because ssl is mandatory for creating users and changing password.

(1) Install Active Directory Domain Services
https://docs.microsoft.com/en-us/windows-server/identity/ad-ds/deploy/install-active-directory-domain-services--level-100-#BKMK_GUI

(2) Install the Certification Authority
https://docs.microsoft.com/en-us/windows-server/networking/core-network-guide/cncg/server-certs/install-the-certification-authority


4. Configure AD Client
=====================================

(1) Install packages
# yum install sssd realmd oddjob oddjob-mkhomedir adcli samba-common samba-common-tools krb5-workstation openldap-clients policycoreutils-python

(2) Update the /etc/hosts file and /etc/resolv.conf so that dns name or hostname of AD server gets resolved correctly.
# cat /etc/resolv.conf
search skycloud.com
nameserver 192.168.171.101

(3) Join Windows Domain
# realm join --user=administrator skycloud.com

(4) Verify
# realm list
skycloud.com
  type: kerberos
  realm-name: SKYCLOUD.COM
  domain-name: skycloud.com
  configured: kerberos-member
  server-software: active-directory
  client-software: winbind
  required-package: oddjob-mkhomedir
  required-package: oddjob
  required-package: samba-winbind-clients
  required-package: samba-winbind
  required-package: samba-common-tools
  login-formats: SKYCLOUD\%U
  login-policy: allow-any-login
skycloud.com
  type: kerberos
  realm-name: SKYCLOUD.COM
  domain-name: skycloud.com
  configured: kerberos-member
  server-software: active-directory
  client-software: sssd
  required-package: oddjob
  required-package: oddjob-mkhomedir
  required-package: sssd
  required-package: adcli
  required-package: samba-common-tools
  login-formats: %U
  login-policy: allow-realm-logins
  
(5) Verify /etc/sssd/sssd.conf to have below entries

[sssd]
domains = skycloud.com
config_file_version = 2
services = nss, pam

[domain/skycloud.com]
ad_domain = skycloud.com
krb5_realm = SKYCLOUD.COM
realmd_tags = manages-system joined-with-samba 
cache_credentials = True
id_provider = ad
krb5_store_password_if_offline = True
default_shell = /bin/bash
ldap_id_mapping = True
use_fully_qualified_names = False
fallback_homedir = /home/%u
access_provider = ad  

(6) Assign appropriate permission to sssd.conf
# chown root:root /etc/sssd/sssd.conf
# chmod 0600 /etc/sssd/sssd.conf
# restorecon /etc/sssd/sssd.conf
# authconfig --enablesssd --enablesssdauth --enablemkhomedir --update
# systemctl enable sssd
# systemctl start sssd

(7) Check and Verify  AD users
# id emma
uid=596401105(emma) gid=596400513(domain users) groups=596400513(domain users),596400572(denied rodc password replication group),596400512(domain admins)
# id emma@skycloud.com
uid=596401105(emma) gid=596400513(domain users) groups=596400513(domain users),596400572(denied rodc password replication group),596400512(domain admins)

(8) Configure for creating home directoryautomatically when first timelogin:
Edit /etc/pam.d/sshd, add a line: 
session    required     pam_mkhomedir.so 

5. Run cbtool command
=====================================

This command will generate configuration file /opt/skyformai/etc/ldap.json. Command "aip" will read this file to connect LDAP server.

(1) Command usage
# ./cbtool l c -h
NAME:
   cbtool ldap config - Configure how to connect LDAP/AD server

USAGE:
   cbtool ldap config [command options] [arguments...]

OPTIONS:
   --type value     ldap|ad (default: "ldap")
   --url value      Specify LDAP/AD server. The following schemas are supported: ldap://, ldaps://, e.g.,'ldap://xxx.xxx.xxx.xxx:389', 'ldaps://xxx.xxx.xxx.xxx:636'. Must use ldaps(ssl) if you need SkyForm AIP creating users to AD.
   --user value     Bind user to be authenticated to LDAP/AD server
   --passwd value   Bind password to be authenticated to LDAP/AD server
   --domain value   Specify LDAP/AD domain, e.g., 'dc=skycloud,dc=com'
   --userCN value   Specify LDAP/AD user organizational unit; LDAP default is 'ou=People'; AD default is 'cn=Users'
   --groupCN value  Specify LDAP/AD group organizational unit; LDAP default is 'ou=Group'; AD default is 'cn=Users'
   --baseUid value  Only for LDAP. New user uid number is incremental from this base uid number (default: 1500)
   --homeDir value  Only for LDAP. User home directory '/$homeDir/$username' (default: "/home")
   --help, -h       show help (default: false)
   
(2) Example: configure OpenLDAP
# ./cbtool l c --type ldap --url ldap://node1:389 --user cn=ldapadm,dc=skycloud,dc=com --passwd password --domain dc=skycloud,dc=com --userCN ou=People --groupCN ou=Group --baseUid 1500 --homeDir /home
{
  "Type": "ldap",
  "Url": "ldap://node1:389",
  "BindUser": "cn=ldapadm,dc=skycloud,dc=com",
  "BindPasswd": "b9be5d791e2ccab7823e826966b04cbad481b21b14ebb6def658a621966fe9a9104f428b",
  "BaseDN": "dc=skycloud,dc=com",
  "UserCN": "ou=People",
  "GroupCN": "ou=Group",
  "BaseUid": 1500,
  "HomeDir": "/home"
}
Config file /opt/skyformai/etc/ldap.json successful

(3) Example: configure AD
# ./cbtool l c --type ad --url ldaps://WIN-EL0APG6RP5N.skycloud.com:636 --user cn=administrator,cn=users,dc=skycloud,dc=com --passwd Letmein1234 --domain dc=skycloud,dc=com --userCN cn=Users --groupCN cn=Users 
{
  "Type": "ad",
  "Url": "ldaps://WIN-EL0APG6RP5N.skycloud.com:636",
  "BindUser": "cn=administrator,cn=users,dc=skycloud,dc=com",
  "BindPasswd": "c25a988a2efb86d8eae55793cf823fb4dce3f1afe4a177ca5b507bb551d8f0803a5485d2b8dab9",
  "BaseDN": "dc=skycloud,dc=com",
  "UserCN": "cn=Users",
  "GroupCN": "cn=Users",
  "BaseUid": 1500,
  "HomeDir": "/home"
}
Config file /opt/skyformai/etc/ldap.json successful

   
6. Run aip command
=====================================

(1) Permissions
#subcommand	      permitted
create	          root, aip admins	
delete	          root, aip admins	
info	          root, aip admins	
changepassword	  root, aip admins, authenticated him/her-self
creategroup	      any user; user who created the group is group admin; root and aip admin can create group for others
deletegroup       root aip admins, group admin	
addmembers        root aip admins, group admin	
delmembers        root aip admins, group admin	

(2) User and group schema (json format)

ldapUser {
	Name          string    // short name
    Dn            string    // full name
	LogonName     string    // only for AD; in format of "username@domain"
    HomeDir       string    // only for ldap; user home directory
	MemberOf      []string  // groups that this user has joined to
}

ldapGroup {
	Name      string       // short name
	Dn        string       // full name
	Admin     string       // the user who created this group
	Member    []string     // users
}

(3) Command usage

# ./aip lu -h
NAME:
   aip ldapuser - External LDAP/AD users

USAGE:
   aip ldapuser command [command options] [arguments...]

COMMANDS:
     create, c           Create a user
     delete, d           Delete a user
     info, i             Display a specified user or all users
     changepassword, cp  Change a user password
     creategroup, cg     Create a user group
     deletegroup, dg     Delete a user group
     infogroup, ig       Display a specified user group or all groups
     addmembers, am      Add members to user group
     delmembers, dm      Delete members from user group
     help, h             Shows a list of commands or help for one command

OPTIONS:
   --help, -h     show help (default: false)
   --version, -v  print the version (default: false)
   
(3) Example
   
[root@node1 go]# ./aip lu c testuser1 password
Add user testuser1 successful
[root@node1 go]# ./aip lu i testuser1
[
  {
    "Name": "testuser1",
    "LogonName": "",
    "Dn": "uid=testuser1,ou=People,dc=skycloud,dc=com",
    "HomeDir": "/home/testuser1",
    "MemberOf": []
  }
]
[root@node1 go]# ./aip lu cp testuser1 newpasswd
Change password successful
[root@node1 go]# ./aip lu cg -a testuser1 grp1
Add group grp1 successful
[root@node1 go]# ./aip lu ig grp1
[
  {
    "Name": "grp1",
    "Dn": "cn=grp1,ou=Group,dc=skycloud,dc=com",
    "Admin": "testuser1",
    "Member": [
      "testuser1"
    ]
  }
]
[root@node1 go]# su testuser1
sh-4.2$ ./aip lu cg
Add group testuser11593317880 successful
sh-4.2$ ./aip lu ig testuser11593317880
[
  {
    "Name": "testuser11593317880",
    "Dn": "cn=testuser11593317880,ou=Group,dc=skycloud,dc=com",
    "Admin": "testuser1",
    "Member": [
      "testuser1"
    ]
  }
]
sh-4.2$ exit
exit
[root@node1 go]# ./aip lu am testuser11593317880 user1
Add member sucessful
[root@node1 go]# ./aip lu ig testuser11593317880
[
  {
    "Name": "testuser11593317880",
    "Dn": "cn=testuser11593317880,ou=Group,dc=skycloud,dc=com",
    "Admin": "testuser1",
    "Member": [
      "testuser1",
      "user1"
    ]
  }
]
[root@node1 go]# ./aip lu i user1
[
  {
    "Name": "user1",
    "LogonName": "",
    "Dn": "uid=user1,ou=People,dc=skycloud,dc=com",
    "HomeDir": "/home/user1",
    "MemberOf": [
      "testuser11593317880"
    ]
  }
]
[root@node1 go]# ./aip lu i testuser1
[
  {
    "Name": "testuser1",
    "LogonName": "",
    "Dn": "uid=testuser1,ou=People,dc=skycloud,dc=com",
    "HomeDir": "/home/testuser1",
    "MemberOf": [
      "grp1",
      "testuser11593317880"
    ]
  }
]
[root@node1 go]# ./aip lu dg testuser11593317880
Delete group testuser11593317880 successful
[root@node1 go]# ./aip lu i testuser1
[
  {
    "Name": "testuser1",
    "LogonName": "",
    "Dn": "uid=testuser1,ou=People,dc=skycloud,dc=com",
    "MemberOf": []
  }
]
[root@node1 go]# ./aip lu d testuser1
Delete user testuser1 successful

