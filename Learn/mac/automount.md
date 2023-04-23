# Mac nfs挂载
## 直接终端挂载
`sudo mount -o resvport [ip]:/share /path/share` _直接从终端挂载到指定目录_

## 自动挂载
```bash
#fstab 方式
vim /etc/fstab #写入，格式为
[ip]:/path/share /path/share nfs resvport 0 0
#eg:
10.0.0.202:home/ve/share  /Users/ve/tmp   nfs    resvport   0 0
sudo mount -a #即可挂载，缺点在于一直挂载状态。

#aumount方式
vim /etc/auto_master 
#
# Automounter master map
#
+auto_master		# Use directory service
#/net			-hosts		-nobrowse,hidefromfinder,nosuid
#/home			auto_home	-nobrowse,hidefromfinder
#/Network/Servers	-fstab
#/-			-static
/Users/ve/share autofs_nfs
#在最后一行添加挂载点 挂载点配置名
```
```bash
vim /etc/autofs_nfs #若无则创建，小心名字别打错了，和上面的配置名一致
#格式：挂载名 挂载参数 [ip]:挂载点
#eg：
share2 -fstype=nfs,rw,bg,hard,intr,tcp,resvport 10.0.0.202:/home/ve/share
share5 -fstype=nfs,rw,resvport 10.0.0.105:/home/t/share
```
```bash
sudo automount -vc  #开启自动挂载
#输出例如
automount: /System/Volumes/Data/Users/ve/share updated (/Users -> /System/Volumes/Data/Users)
automount: no unmounts

mount # 查看挂载情况
showmount -e 10.0.0.202 #查看机器nfs服务暴露情况

vim /etc/autofs.conf #设置默认卸载时间
# The number of seconds after which an automounted file system will
# be unmounted if it hasn't been referred to within that period of
# time.  The default is 10 minutes (600 seconds).
# This is equivalent to the -t option in automount(8).
AUTOMOUNT_TIMEOUT=600
```
**优势：使用到该挂载点时才会自动挂载，不用时，或者过了时间，自动不挂载**

[参考1](https://www.douban.com/note/728609194/#:~:text=MAC%20OS%20X自动挂载NFS%201,首先检查autofs相关服务%202%20使用Autofs自动挂载NFS....%203%20输出如下?_i=0375669Bs0zVOm)