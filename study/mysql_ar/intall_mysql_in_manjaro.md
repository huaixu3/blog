# 安装mysql（MariaDb）在manjaro中

## install
```bash
sudo pacman -S mysql
```
## 初始化
```bash
sudo mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
```
## 配置
```bash
sudo systemctl start mysqld
sudo /usr/bin/mysql_secure_installation
# 第一个是输入密码，默认是无（即直接回车）
# 第三个是是否改变密码
# 第四个禁止远程root登录
# 第五个重新载入权限表
```
## 使用
    * 进入 
        mysql -u root -p
    * 增加用户
        CREATE USER 'a'@'localhost' IDENTIFIED by 'mysql_a';


