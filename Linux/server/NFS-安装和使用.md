# NFS-安装和使用

*转载请注明出处*

---
> 云盘让你接触云端，NFS让你云端的机器不那么远  
> 初识分不清目录与挂载，再见只叹相识恨晚。又是一个很香的服务。

## NFS服务端配置安装
> NFS(Network File System)网络文件系统  
> RPC（Remote Procedure Call)远程程序调用
```bash
#服务端安装nfs和rpc
yum install nfs-utils rpcbind -y 

#配置文件/etc/exports
/path (rw,no_root_squash,no_all_squash,sync)
#eg:修改配置文件/etc/exports
/root/nfs 192.168.1(rw,no_root_squash,sync) #指定ip
/mnt/nfs *(rw,all_squash,anonuid=1000,anongid=1000,sync)#所有人都可以连，无权限
#重新载入挂载点
exportfs -r
#启动nfs服务和设置开机自启动
systemctl start nfs
systemctl enable nfs
#关闭firewalld
systemctl disable firewalld.service
```
## NFS客户端安装和配置
```bash
#安装nfs和rpc
yum install nfs-utils rpcbind -y
#挂载远端
mount -t nfs [ip]:/root/nfs /root/nfs

# 查看远端nfs的暴露情况
showmount -e [ip]

# 开机自动挂载
在/etc/fstab中添加
192.168.59.129:/share      /share      nfs  defaults  0  0

```

## 管理命令选项
权限属性：

| option          | function       | remark                 |
|-----------------|----------------|------------------------|
| ro              | 只读           |                        |
| rw              | 读写           |                        |
| sync            | 同步           | 数据同步到内存和硬盘中 |
| async           | 异步           | 数据先暂存内存         |
| root_squash     | root权限压缩   | root映射成guest        |
| no_root_squash  | root权限不压缩 | 拥有root权限           |
| all_squash      | 所有权限压缩   | 所有的映射成同一个     |
| no_all_squash   | 所有的不压缩   | 所有的不压缩           |
| anonuid,anongid | 指定id         | 指定映射的uid和gid     |

exportfs 命令选项：

| option | function | remark        |
|--------|----------|---------------|
| a      | all      | 一般和r/u连用 | 
| r      | 重新导入 |               |
| u      | 取消导入 |               |
| v      | version  | 版本信息      |

showmount 命令选项：（显示关于nfs服务器挂载信息）

| option | function    | remark                   |
|--------|-------------|--------------------------|
| e      | export      | 列出nfs服务输出清单      |
| a      | all         | 显示客户主机名和挂载目录 |
| d      | directories | 仅显示被用户挂载的目录   |


## 简要原理

nfs端口：2049  
rpcbind端口：111  
服务端共享文件系统，客户端通过rpc调用  

---
**参考**：
- [搭建案例](https://www.cnblogs.com/whych/p/9196537.html#:~:text=NFS%E6%9C%AC%E8%BA%AB%E7%9A%84%E6%9C%8D%E5%8A%A1%E5%B9%B6%E6%B2%A1%E6%9C%89%E6%8F%90%E4%BE%9B%E6%95%B0%E6%8D%AE%E4%BC%A0%E9%80%92%E7%9A%84%E5%8D%8F%E8%AE%AE%EF%BC%8C%E8%80%8C%E6%98%AF%E9%80%9A%E8%BF%87%E4%BD%BF%E7%94%A8RPC%EF%BC%88%E8%BF%9C%E7%A8%8B%E8%BF%87%E7%A8%8B%E8%B0%83%E7%94%A8%20Remote%20Procedure%20Call%EF%BC%89%E6%9D%A5%E5%AE%9E%E7%8E%B0%E3%80%82,%E5%BD%93NFS%E5%90%AF%E5%8A%A8%E5%90%8E%EF%BC%8C%E4%BC%9A%E9%9A%8F%E6%9C%BA%E7%9A%84%E4%BD%BF%E7%94%A8%E4%B8%80%E4%BA%9B%E7%AB%AF%E5%8F%A3%EF%BC%8CNFS%E5%B0%B1%E4%BC%9A%E5%90%91RPC%E5%8E%BB%E6%B3%A8%E5%86%8C%E8%BF%99%E4%BA%9B%E7%AB%AF%E5%8F%A3%E3%80%82%20RPC%E5%B0%B1%E4%BC%9A%E8%AE%B0%E5%BD%95%E4%B8%8B%E8%BF%99%E4%BA%9B%E7%AB%AF%E5%8F%A3%EF%BC%8CRPC%E4%BC%9A%E5%BC%80%E5%90%AF111%E7%AB%AF%E5%8F%A3%E3%80%82%20%E9%80%9A%E8%BF%87client%E7%AB%AF%E5%92%8Csever%E7%AB%AF%E7%AB%AF%E5%8F%A3%E7%9A%84%E8%BF%9E%E6%8E%A5%E6%9D%A5%E8%BF%9B%E8%A1%8C%E6%95%B0%E6%8D%AE%E7%9A%84%E4%BC%A0%E8%BE%93%E3%80%82%20%E5%9C%A8%E5%90%AF%E5%8A%A8nfs%E4%B9%8B%E5%89%8D%EF%BC%8C%E9%A6%96%E5%85%88%E8%A6%81%E7%A1%AE%E4%BF%9Drpc%E6%9C%8D%E5%8A%A1%E5%90%AF%E5%8A%A8%E3%80%82)
- [百科](https://baike.baidu.com/item/%E7%BD%91%E7%BB%9C%E6%96%87%E4%BB%B6%E7%B3%BB%E7%BB%9F/9719420)
