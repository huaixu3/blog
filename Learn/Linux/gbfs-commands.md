# gbfs  
> 并行文件系统管理


## 常用命令
```bash
mmstartup       # 并行文件系统启动
mmgetstate -Lsa # 并行文件系统状态
mmshutdown      # 停止并行文件系统
mmlsdisk        # 查看磁盘状态
# 配额相关管理
mmchfs [disk] -Q yes   # 查询配额状态
mmquotaon -a           # 开启配额
mmdefquotaon -a        # 开启默认配额
mmdefequota -u [disk]  # 修改默认用户的限额
mmlsquota -d -u [disk] # 查看新用户默认配额
mmcheckquota -a        # 检查quota
mmedquota -u [user]    # 为某用户设置磁盘配额
mmrepquota -a          # 查看所有用户配额
mmlsquota              # 查看自己的配额
mmrepquota [disk]      # 查看文件系统配额状态

```
