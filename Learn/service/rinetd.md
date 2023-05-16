# rinetd端口转发

## 下载安装
`yum -y install gcc gcc-c++ make` _安装依赖_
`wget https://github.com/samhocevar/rinetd/releases/download/v0.70/rinetd-0.70.tar.gz` _下载rinetd_
`tar xf rinetd-0.70.tar.gz` _解压_
```bash
cd rinetd-0.79
./bootstrap
./configure
make&& make install #编译安装
rinetd -v #查看版本以确定是否安装完毕
```

## 配置
```bash
#编辑文件进行配置
vi /etc/rinetd.conf 
0.0.0.0 18081 192.168.0.109 18081
0.0.0.0 2222 192.168.0.103 3389
1.2.3.4 80     192.168.0.10 80
#将本地的18081端口转发到192.168.0.109的18081端口
#能够转发的地址 本机端口 目标ip 目标端口
# 须关闭防火墙或配置防火墙放行
#设只udp转发
vi /etc/rinetd.conf
127.0.0.1 8000/udp 192.168.1.2 8000/udp

```
`pkill rinetd`  _关闭进程_
`rinetd -c /etc/rinetd.conf`  _启动转发_
`echo "rinetd -c /etc/rinetd.conf ">>/etc/rc.local` _开机自动运行_
`netstat -antup` _查看是否运行正常_
