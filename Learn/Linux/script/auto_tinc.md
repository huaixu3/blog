# 自动填写tinc配置信息
```bash
#!bin/sh

#client config
#host name
name=clienthostname
#tinc path
#tinc_dir=/etc/tinc
tinc_dir=/home/ve/tmp
tinc_net_name=mhyt
#client本机内网ip
tinc_net_ip=10.0.0.5
#server公网ip
tinc_server_name=tinc_ali
tinc_public_ip=10.0.0.10

#server config
#是否是服务节点,1是，0不是，默认为0
isServer=0


# 设置服务启动
echo "$tinc_net_name " >> $tinc_dir/nets.boot

if [ ! -d $tinc_dir/$tinc_net_name ];
then
        mkdir -p $tinc_dir/$tinc_net_name/hosts;
        touch  $tinc_dir/$tinc_net_name/tinc.conf;
fi

echo "Name = $name " > $tinc_dir/$tinc_net_name/tinc.conf
if [ $isServer -eq 0 ]
then
        echo "ConnectTo $tinc_server_name " >> $tinc_dir/$tinc_net_name/tinc.conf
fi

echo "#!/bin/sh " > $tinc_dir/$tinc_net_name/tinc-up
echo "ifconfig \$INTERFACE $tinc_net_ip netmask 255.255.0.0 " >> $tinc_dir/$tinc_net_name/tinc-up
chmod +x $tinc_dir/$tinc_net_name/tinc-up

echo "#!/bin/sh " > $tinc_dir/$tinc_net_name/tinc-down
echo "ifconfig \$INTERFACE down " >> $tinc_dir/$tinc_net_name/tinc-down
chmod +x $tinc_dir/$tinc_net_name/tinc-down

#创建本机描述文件

if [ $isServer -eq 1 ];
then
        echo "Address = $tinc_public_ip " >> $tinc_dir/$tinc_net_name/hosts/$name
fi
echo "Subnet = $tinc_net_ip " >> $tinc_dir/$tinc_net_name/hosts/$name


# 待做的事
# sudo tincd -n mhyt -K
# 交换密钥
# 启动服务
```
