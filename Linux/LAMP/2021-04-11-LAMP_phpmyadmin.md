## LAMP
    - L 选择manjaro（centos更适合做服务器）
    - A apche
    - M mysql （参考上前面）
    - P php
```bash
pacman -S mysql php php7 php7-fpm php7-apche
#打开文件/etc/httpd/conf/httpd.conf
#注释掉
LoadModule mpm_event_module modules/mod_mpm_event.so
#然后取消掉这一行的注释，一般在前一的后面
LoadModule mpm_prefork_module modules/mod_mpm_prefork.so
# 把下面两行放在LoadModule模块的后面
LoadModule php_module modules/libphp.so
AddHandler php-script .php
# 把下面这个放在Include模块的后面
Include conf/extra/php_module.conf
#最后需要重启httpd服务
```
### 测试php是否安装成功
在/srv/http/中建立一个php文件 写入
```
<?php
 phpinfo();
?>
```
打开如果能显示php的版本等信息即为php搭建成功，进行下一步


## 安装phpmyadmin (本文重点）
```bash 
yay -S phpmyadmin #安装之后路经在/usr/share/webapps/phpMyAdmin
vim /etc/php/php.ini
extension=pdo_mysql.so
extension=mysqli.so
#取消掉这两行的注释，以启动扩展，注PHP 7.0 中 删除了mysql.so。
#可以给网络脚本最低的 MySQL 用户权限，可以编辑 /etc/mysql/my.cnf 取消 skip-networking 行的注释，这样 MySQL 服务器就只能本地访问。设置之后需要重启 MySQL。
#也可以启用 extension=bz2 和 extension=zip 扩展以支持压缩

#创建Apache配置文件
/etc/httpd/conf/extra/phpmyadmin.conf
Alias /phpmyadmin "/usr/share/webapps/phpMyAdmin"
<Directory "/usr/share/webapps/phpMyAdmin">
    DirectoryIndex index.php
    AllowOverride All
    Options FollowSymlinks
    Require all granted
</Directory>
#在/etc/httpd/conf/httpd.conf加入配置文件：
Include conf/extra/phpmyadmin.conf
```
之后打开localhost/phpmyadmin即可看到登录界面，如果看不到可以选择手动链接（或者拷贝）phpmyadmin到/srv/http目录然后手动打开index.php文件也可

[参考phpmyadmin](https://wiki.archlinux.org/index.php/PhpMyAdmin)  
[参考apache](https://wiki.archlinux.org/index.php/Apache_HTTP_Server#PHP)
