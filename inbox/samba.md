## install
```bash
pacman -S samba
yum install samba

```
## 配置
```bash
# 在文件 /etc/samba/smb.conf 中增加配置
# testparam 检查配置是否有错
# smbpasswd -a ve 设置用户密码

[ve]
        comment = ve guest share  #共享描述
        path = /home/ve       #共享目录
        public = yes                #允许guest用户访问
        writable = yes              #允许在ve目录下写入
        directory mask = 0755       #默认创建目录权限
        create mask = 0611          #默认创建文件权限
        valid users = ve,root  #允许访问该共享的用户
        write list = ve,root  #可写入共享的用户列表
        browseable = yes             #该指定共享目录可浏览
        available = yes              #该指定共享资源可使用
