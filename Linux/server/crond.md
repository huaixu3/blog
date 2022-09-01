## 服务的起停
```bash
systemctl start crond
systemctl stop crond
systemctl enable crond
systemctl disenable crond
systemctl reload crond
systemctl status crond
```


## format
```bash
# minute hour day-of-month month-of-year day-of-week commands 
# 00-59  00-23 01-31       01-12         0-6 (0 is sunday) 
"*"代表所有的取值范围内的数字
"/"代表每的意思
"/5"表示每5个单位
"-"代表从某个数字到某个数字
","分开几个离散的数字

-l 在标准输出上显示当前的crontab。 
-r 删除当前的crontab文件。 
-e 使用VISUAL或者EDITOR环境变量所指的编辑器编辑当前的crontab文件
```
```bash
#example
0 6 * * * echo "Good morning." >> /tmp/test.txt
#每天早上6点
0 */2 * * * echo "Have a break now." >> /tmp/test.txt
# 每两个小时
0 23-7/2，8 * * * echo "Have a good dream" >> /tmp/test.txt
# 晚上11点早上八点之间每两小时和早上八点
01 * * * * root run-parts /etc/cron.hourly
# 每小时 
02 4 * * * root run-parts /etc/cron.daily
# 每天 

* * * * * /root/mysql_backup_script.sh
每分钟
