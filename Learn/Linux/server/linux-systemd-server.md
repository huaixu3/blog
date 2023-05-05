# linux systemd server

- 管理自己的服务后台运行

## 文件夹作用
/etc/init.d _系统服务的启动脚本。这些脚本用于控制在系统启动和关闭时哪些服务需要启动或停止_  
/etc/systemd/system/   
/usr/lib/systemd/system/ _系统服务文件，控制系统服务启停_  

## 创建一个服务来控制nacos 
```bash
vim /etc/systemd/system/mynacos.service  
## 填写以下内容
[Unit]
Description=My nacos Service
After=network.target

[Service]
Type=forking
#Type=notify
#Type=simple
#WorkingDirectory=/root/000workspace/nacos
ExecStart=/root/000workspace/nacos/bin/startup.sh -m standalone
ExecStop=/root/000workspace/nacos/bin/shutdown.sh

[Install]
WantedBy=multi-user.target
# [Unit] 区块用于描述服务本身， [Service] 区块用于描述服务如何运行， [Install] 区块定义服务如何启动
## 填入结束

systemctl daemon-reload # 重新加载，以发现mynacos服务
systemctl start mynacos
systemctl status mynacos # 查看服务状态
```
