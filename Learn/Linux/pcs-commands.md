# pcs 服务管理 
> pcs高可用服务集群

## 服务状态的查看
```sh 
pcs status
pcs resource cleanup # 错误日志清除 
```
## 服务的创建
```sh
pcs resource list # 查看可用资源
# vip
pcs resource delete  mhyt_portal_vip_192.167.253.112
pcs resource create mhyt_portal_vip_192.167.253.112 ocf:heartbeat:IPaddr2  ip="192.167.253.112" flush_routes=true op monitor interval=10s timeout=20s
#nginx 
pcs resource create mhyt_nginx ocf:heartbeat:nginx op monitor interval=10s timeout=30s
#httpd 
pcs resource create mhyt_httpd ocf:heartbeat:apache configfile=/etc/httpd/conf/httpd.conf \
op monitor interval=10s timeout=20s
#gateway 
pcs resource create mhyt_studio_gateway systemd:gateway op monitor interval=10s timeout=100s
#appspace
pcs resource create mhyt_studio_appspace systemd:appspace op monitor interval=10s timeout=100s
```
## 服务组的创建
```sh
# resource group add/remove 
# 同一资源组中的服务会在同一台机器上运行
pcs resource group add mhyt_studio_group mhyt_nginx mhyt_studio_appspace
pcs resource group remove mhyt_studio_group mhyt_nginx mhyt_studio_appspace
# pcs clone
pcs resource clone mhyt_studio_group # 克隆的资源会在所有节点上运行
pcs resource clone mhyt_studio_group clone-max=2 notify=true
pcs resource unclone mhyt_studio_group # 取消克隆
#clone-max=2 notify=true
```
## 服务的限制和偏好
```sh
# resource prefer and avoids
pcs constraint location mhyt_studio_group-clone avoids mgt03
pcs constraint location mhyt_portal_vip_192.167.253.113  prefers mgt01 
# 删除某条规则限制
pcs constraint location remove location-mhyt_studio_group-clone-mgt01--INFINITY
```
## 机器的维护和服务
```sh
# 资源服务查看
pcs config
# 机器维护 
pcs node standby mgt03
pcs node unstandby mgt03

pcs cluster stop --all # 关闭所有主机
pcs cluster start --all # 开启所有主机

pcs cluster node remove <node>  # 删除指定节点，从集群中

# config update runing
pcs cluster cib ra_cfg                # 将群集资源配置信息保存在指定文件
pcs -f ra_cfg resource show           # 显示指定文件的配置信息，检查无误
pcs cluster cib-push ra_cfg           # 将指定配置文件加载到运行配置中
```

参考[https://www.cnblogs.com/ethanxzw/p/13728210.html](https://www.cnblogs.com/ethanxzw/p/13728210.html)
