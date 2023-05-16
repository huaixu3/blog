#hello ldap

# run ldap
```bash
docker run --name my-openldap-container --detach osixia/openldap:1.2.2
docker exec -it my-openldap-container bash
slaptest
ldapsearch -x -H ldap://localhost -b dc=example,dc=org -D "cn=admin,dc=example,dc=org" -w admin
```
# 基础知识
框架图
![](https://camo.githubusercontent.com/c7f6fa1fbb9249e2ea2a2b27d7729143d4197540fe856a572fd66d73755fcba8/68747470733a2f2f75706c6f61642d696d616765732e6a69616e7368752e696f2f75706c6f61645f696d616765732f393736373030392d656132393933626364643437633162322e706e673f696d6167654d6f6772322f6175746f2d6f7269656e742f7374726970253743696d61676556696577322f322f772f31323430)
- dc 最上层是顶层分类的域名（net、com、org）
- dc 第二层是组织层（example、github、等等） 
>dc为分类和名称的定位，可唯一定位一个组织
- ou 第三层是组织部门层Unit(各个部门层People、server组等)
- uid 第四层是用户层精确到个人（babu等）person

名词解释
![](https://camo.githubusercontent.com/401afa7d0e0713e9ea5d5bdff6b6ce43239d0626f10cce25cc763a48606cac0c/68747470733a2f2f75706c6f61642d696d616765732e6a69616e7368752e696f2f75706c6f61645f696d616765732f393736373030392d613834633563303063656530393763372e706e673f696d6167654d6f6772322f6175746f2d6f7269656e742f7374726970253743696d61676556696577322f322f772f31323430)
树状图

![](https://camo.githubusercontent.com/3596a436aace6df6e420deab05f3ab33fdeefd5de2f7e363daf50751334175b3/68747470733a2f2f75706c6f61642d696d616765732e6a69616e7368752e696f2f75706c6f61645f696d616765732f393736373030392d376237663064633964663138663266382e706e673f696d6167654d6f6772322f6175746f2d6f7269656e742f7374726970253743696d61676556696577322f322f772f31323430)

## ldap 增删改查

```bash
ldapmodify [ldap 服务器地址] [你的用户名] [你的密码] [ldif 文件的地址]
```
![](https://camo.githubusercontent.com/0b1ce21373f751c365b3fe398499af70d0f569cc1c2cd02c68b428d35d747203/68747470733a2f2f75706c6f61642d696d616765732e6a69616e7368752e696f2f75706c6f61645f696d616765732f393736373030392d313865366533663763363136653035372e706e673f696d6167654d6f6772322f6175746f2d6f7269656e742f7374726970253743696d61676556696577322f322f772f31323430)
```bash
# file name babu.ldif
dn: cn=babu,dc=example,dc=org
objectClass: inetOrgPerson
cn: babu
sn: lee
title: the world most famous mythical manger
mail: babu@example.com
uid: baubulee
```
```bash
ldapadd -x -H ldap://127.0.0.2:389 -D "cn=admin,dc=example,dc=org" -w admin -f barbara.ldif
ldapsearch -x -H ldap://127.0.0.2:389  -b dc=example,dc=org -D "cn=admin,dc=example,dc=org" -w admin 
ldapsearch -x -H ldap://127.0.0.2:389  -b dc=example,dc=org -D "cn=admin,dc=example,dc=org" -w admin "cn=*"
ldapdelete -x -H ldap://127.0.0.2:389  -D "cn=admin,dc=example,dc=org" -w admin  "cn=barbara,dc=example,dc=org"

dn: cn=barbara,dc=example,dc=org
changetype: add
objectClass: inetOrgPerson
cn: barbara
sn: Jensen
title: the world most famous mythical manager
mail: bjensen@example.com
uid: bjensen

ldapmodify -x -H ldap://127.0.0.2:389 -D "cn=admin,dc=example,dc=org" -w admin -f barbara.ldif

```
```bash
#file name : addorg.ldif
dn: ou=People,dc=example,dc=org
changetype: add
objectclass: top
objectclass: organizationalUnit
ou: People

dn: ou=Servers,dc=example,dc=org
changetype: add
objectclass: top
objectclass: organizationalUnit
ou: Servers

#file name :modify1.ldif
dn: cn=barbara,dc=example,dc=org
changetype: modify
replace: title
title: one of the world most famous mythical manager

# file name: modify2.ldif
dn: cn=barbara,dc=example,dc=org
changetype: modify
add: description
description: barbara description

# file name: modify3.ldif

dn: cn=barbara,dc=example,dc=org
changetype: modrdn
newrdn: cn=babara
deleteoldrdn: 0
newsuperior: ou=People,dc=example,dc=org

```

## 用户密码
- ldappasswd 用于重置其他用户的密码
- ldapmodify 用于更改自己的密码
```bash
ldappasswd -x -H ldap://127.0.0.2:389 -D "cn=admin,dc=example,dc=org" -w admin  "cn=barbara,dc=example,dc=org"
ldappasswd -x -H ldap://127.0.0.2:389 -D "cn=barbara,dc=example,dc=org" -w xxxx -s mima

#file name : passwd.ldif
dn: cn=barbara,dc=example,dc=org
changetype: modify
replace: userPassword
userPassword: xinmima

ldapmodify -x -H ldap://127.0.0.2:389 -D "cn=barbara,dc=example,dc=org" -w mima -f passwd.ldif

```

