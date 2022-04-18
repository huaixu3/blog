*本文非原作者:[源地址](https://zhuanlan.zhihu.com/p/105482468)*   
*本文只是对原文做了个人的简化与修改* 

## 用户
 - 根用户 root
 - 普通用户
 - 用户组 ：用户的分组
 
## 用户信息记录
- /etc/passwd —— 管理用户UID/GID重要参数
- /etc/shadow —— 管理用户密码
- /etc/group —— 管理用户组相关信息
- /etc/gshadow —— 管理用户组管理员相关信
### /etc/passwd
该文件中，每一行的存储格式为：
>账号名称 : 密码 : UID : GID : 用户信息说明列 : 主文件夹 : shell  
>root : x : 0 : 0 : root : /root : /bin/bash  

密码不显示，移至/etc/shadow中

### /etc/shadow 
该文件中，每一行的存储格式为：
> 账号名称 : 密码 : 最近改动密码的日期 : 密码不可被改变的天数 : 密码需要重新更改的天数 : 更改提醒天数 : 密码过期后账号的宽限时间 : 账号失效日期 : 保留  
> root : (字符串，此处打码) : 200 : 0 : 99999 : 7 : : :  

### /etc/group
该文件中，每一行的存储格式为：
>用户组名称 : 用户组密码 : GID : 此用户组包含的账号名称  
>root : x : 0 : root  

用户组密码为了设置组管理员，密码信息移至/etc/gshadow
### /etc/gshadow
该文件中，每一行的存储格式为：
>用户组名 : 密码 : 用户组管理员账号 : 该用户组包含的账号名称  
>root : : : root  

## 用户管理
| 功能         | 命令    | 使用                         | remark                                 |
|--------------|---------|------------------------------|----------------------------------------|
| 新增用户     | useradd | useradd [option] [usrname]   | /etc/login.defs 、/etc/default/useradd |
|              | adduser |                              | 更偏程序化一点，会自动创建家目录等     |
| 设置密码     | passwd  | passwd [options] [username]  | 与useradd类似                          |
| 改变用户信息 | usermod | usermod [options] [username] | 修改保存在/etc/passwd中的信息          |
| 删除用户     | userdel | userdel [options] [username] | 删除用户及信息（测试时家目录未删除}    |
|              | deluser |                              | 和adduser类似                          |
- 用户在创建的时候会根据login.defs 和useradd来默认指定，如果不添加控制的话
- /etc/default/useradd
```bash
GROUP = 100                            # 默认的用户组  
HOME = /home                           # 默认的主文件夹所在目录  
INACTIVE = -1                          # 密码失效日  
EXPIRE =                               # 账号失效日  
SHELL = /bin/shell                     # 默认shell  
SKEL = /etc/skel                       # 用户主文件夹的内容数据参考目录  
CREATE_MAIL_SPOOL = yes                # 是否创建邮件信箱  
```
- /etc/login.defs  
```bash
PASS_MAX_DAYS       99999           # 多久必须重设密码（天）  
PASS_MIN_DAYS       0               # 距上次修改密码多久不可重设密码（天）  
PASS_MIN_LEN        5               # 密码最短的字符长度  
PASS_WARN_AGE       7               # 距离多少天过期会报警提示  
UID_MIN             500             # 创建用户的UID默认最小值  
UID_MAX             60000           # 创建用户的UID上限  
GID_MIN             500             # 创建用户的GID默认最小值  
GID_MAX             60000           # 创建用户的GID上限  
USERGROUPS_ENAB     yes             # 删除用户时是否删除初始用户组（组内不再有其他成员）  
MD5_CRYPT_ENAB      yes             # 密码是否经过MD5加密  
```

## 用户组管理
| 功能       | 命令     | 使用                           | remark                               |
|------------|----------|--------------------------------|--------------------------------------|
| 添加用户组 | groupadd | groupadd [options] [groupname] | 与useradd类似，不需要设置密码        |
|            | addgroup |                                | 与adduser类似                        |
| 修改用户组 | groupmod | groupmod [options] [groupname] | 修改group相关参数，不建议修改gid     |
| 删除用户组 | groupdel | groupdel [options] [groupname] | 删除前需要保证无任何用户以它为默认组 |
|            | delgroup |                                | 与deluser相似                        |

## 身份切换 sudo su
- su
```bash
 su [options] [username]
options：
-：代表使用 login-shell 的变量文件读取方式来登录系统
-l：同上
-m：表示使用当前的环境设置，而不读取新用户的配置文件
-c：仅进行一次命令，执行完后直接回到目前的用户身份
```
- 
   - 若空默认为root用户  
   - “su -” 表示切换身份的同时读取目标用户的 login-shell ，通常建议使用这一方式切换身份。  
   - 另外，在普通用户切换到 root 用户时，需要 root 用户的登录密码，才能成功切换。这里又涉及到一个安全问题，如何让指定的普通用户具备 root 权限的同时，不让其知道 root 的登录密码呢？这就需要使用 sudo 命令了。

- sudo 
    - 普通用户可以通过 sudo 命令，使用 root 用户权限来执行命令。
    - 该用户需要在 /etc/sudoers文件里面
- /etc/sudoers
![sudoers](https://pic4.zhimg.com/80/v2-828506b937e3242327cdd9459ed59b07_720w.jpg)
```bash
#图中第一行，表示可执行 sudo 的单个用户白名单
root              ALL=(ALL:ALL)                                         ALL
用户账号          登录者来源主机名=(可切换身份：身份所在用户组)           可执行命令
#图中第二行，表示可执行 sudo 的用户组白名单
root              ALL=(ALL:ALL)                                         ALL
用户账号          登录者来源主机名=(可切换身份：身份所在用户组)           可执行命令
```
- 例子
```bash
testuser            ALL=(ALL:ALL)               ALL
testuser            ALL=(root:root)             ALL
testuser            ALL=(root:root)             /usr/bin/passwd
```
## 查询用户信息
```bash
id <user>                           # 展示指定user的UID、GID、用户组信息等，默认为当前有效用户
who am i                            # 等同于 who -m，仅显示当前登录用户相关信息
whoami                              #   仅显示当前有效用户的用户名
w                                   # 展示当前正在登录主机的用户信息及正在执行的操作
who                                 # 展示当前正在登录主机的用户信息
last <user>                         # 展示指定用户的历史登录信息，默认为当前有效用户
lastlog -u <user>                   # 展示指定用户最近的一次登录信息，默认显示所有用户
```

