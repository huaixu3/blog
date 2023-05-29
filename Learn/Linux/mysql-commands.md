# mysql 常用命令

```bash 
mysql -u [user] -p[password]   -h [ip/hostname] [database] 

# 查看一个数据库中那个表各个表使用的存储情况，并排序
 select
 table_schema as '数据库',
 table_name as '表名',
 table_rows as '记录数',
 truncate(data_length/1024/1024, 2) as '数据容量(MB)',
 truncate(index_length/1024/1024, 2) as '索引容量(MB)'
 from information_schema.tables
 where table_schema='test'
 order by data_length desc, index_length desc;
 # 其中table_schema 为查看的数据库名
 ```
