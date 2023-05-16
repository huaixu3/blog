# 数据库运维 devOps

## 数据库线程操作
```bash    
# 查看数据库当前的进程，看一下有无正在执行的慢SQL记录线程。
mysql> show  processlist;
# id      = process id
# user    =
# host    = 显示这个语句是从哪个ip的哪个端口上发出的。可以用来追踪出问题语句的用户。
# db      = 显示这个进程目前连接的是哪个数据库。
# command = ，显示当前连接的执行的命令，一般就是休眠（sleep），查询（query），连接（connect）。
# time    = 状态持续的时间，单位是秒。
# state   = 显示使用当前连接的sql语句的状态
# info    = 显示这个sql语句，因为长度有限，所以长的sql语句就显示不全。
# 杀死进程 
mysql> kill [id]
# 查看当前的事务
mysql> SELECT * FROM information_schema.INNODB_TRX;
# 当前出现的锁
mysql> SELECT * FROM information_schema.INNODB_LOCKs;
#锁等待的对应关系
mysql> SELECT * FROM information_schema.INNODB_LOCK_waits;
# 解释：看事务表INNODB_TRX，里面是否有正在锁定的事务线程，
# 看看ID是否在show processlist里面的sleep线程中，
# 如果是，就证明这个sleep的线程事务一直没有commit或者rollback而是卡住了，我们需要手动kill掉。
# 批量删除事务表中的事务
#通过information_schema.processlist表中的连接信息生成需要处理掉的MySQL连接的语句临时文件，然后执行临时文件中生成的指令。
mysql> select concat('KILL ',id,';') from information_schema.processlist p inner
 join information_schema.INNODB_TRX x on p.id = x.trx_mysql_thread_id where db='test';
```
