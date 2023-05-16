## 环境
> centos-8  
> server:vsftp  
> client:koder 、Fe file explore、(能提供链接ftp 的软件都可）

## 服务器端

### 安装
```bash
dnf install -y vsftp
```
### 配置
>配置文件在 /etc/vsftpd/  
> /etc/vsftpd/vsftpd.conf

```bash
nvim /etc/vsftp/vsftpd.conf

anonymous_enable=NO #不能访客访问
local_enable=YES #本地用户登录
write_enable=YES #准许写
listen_ipv6=NO # 关闭ipv6
listen=YES #ipv4监听打开
```

### 运行
```bash
systemctl start vsftpd #开启vsftp服务
systemctl enable vsftp #每一次开机自启动服务
#在阿里云控制端中修改安全组访问（开放端口20,21）
```

## 客户端（client）端
### koder
- 填写相应的ip，端口，用户名即可。链接模式哪里选择Active（port）模式
![koder](https://img-blog.csdnimg.cn/20210613155045923.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center=400*400)
### Fe file explore
-  交互要人性化一点，但pro版收费很烦
![fe](https://img-blog.csdnimg.cn/20210613155130426.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)

