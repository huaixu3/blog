# redis 缓存服务 

```bash
# 登录
redis-cli -h [ip/hostname] -a [password]
ping # 测试连接是否正常 pong
# 查看使用情况，内存等
info
info memory # 查看内存信息
info server # 查看服务版本等信息
# 查看各个值内存使用大小 
MEMORY USAGE key # 4.0以上 
DEBUG OBJECT key # 4.0以下
#serializedlength:296175300  # 占用内存数，单位为Byte，换算成m除以1024*1024，为296兆
#ql_nodes:110280  # 有的列表个数，比如这里有110280条数据

# 查看键值类型
type [key]
# 查看所有键值对
keys *

# 字符String、列表List、集合Set、哈希Hash、Sorted Set有序集合 
set aa aavalue # 设置一个键值String类型
get aa  # 获取aa的内容
del aa  # 删除aa，返回值为删除的个数 1，表示删除了一个
# hash
hset myhash a avalue # hash类型：设置一个键值 
hmset myhash a avalue b bvalue c cvalue # hash 类型，设置多个键值
hget myhash a # 获取myhash中a的值
hgetall  # 获取所有值
hdel myhash a # 删除hash中a的值
del myhash # 删除myhash这个键值
# List 键值
lpush mylist a b c d e f g # 创建一个list类型的键值
lrange mylist 0 10 # 查看前11个列表的值
lrem mylist 3 a # 删除前三个中值为a的内容 

```
