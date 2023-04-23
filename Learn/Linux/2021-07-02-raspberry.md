## 基础
### 安装系统
- [下载]
在[官网](https://www.raspberrypi.org/software/)下载安装包，并检验镜像包是否完整
- [烧录] 
    - linux : sudo dd if=**.iso of=/dev/sdb 
    - windows下: 请通过官方提供的烧录软件或refus等烧录
- [开机配置时区、密码]
    - 时区选择shanghai，并更新一下时间，时区错误或者不对可能导致浏览器错误，或者终端无法打开
- [换源、更新软件包]
若觉得默认源速度慢，可通过换源提升速度，参考[网站](https://zhuanlan.zhihu.com/p/129881626#:~:text=%E6%A0%91%E8%8E%93%E6%B4%BE%E5%88%B7%E5%A5%BD%E7%B3%BB%E7%BB%9F%E5%90%8E%E4%B8%80%E8%88%AC%E6%83%85%E5%86%B5%E4%B8%8B%E9%83%BD%E6%98%AF%E5%9B%BD%E5%A4%96%E7%9A%84%E6%BA%90%EF%BC%8C%E6%89%80%E4%BB%A5%E8%AF%B4%E5%8F%8A%E5%85%B6%E7%9A%84%E6%85%A2%E3%80%82%20%E5%8F%AF%E4%BB%A5%E6%8D%A2%E6%88%90%E5%9B%BD%E5%86%85%E7%9A%84%E6%BA%90%E3%80%82%20%E5%85%B6%E5%AE%9E%E5%BE%88%E7%AE%80%E5%8D%95%20%E5%8F%AF%E4%BB%A5%E7%9C%8B%E5%88%B0codename%E4%B8%BAbuster%2C%E6%89%80%E4%BB%A5%E4%B8%80%E4%BC%9A%E6%8D%A2%E6%BA%90%E7%9A%84%E6%97%B6%E5%80%99%E4%B8%80%E5%AE%9A%E8%A6%81%E8%AE%B0%E4%BD%8F%E3%80%82%201%3Anano%20%E7%BC%96%E8%BE%91%2Fetc%2Fapt%2F%E7%9B%AE%E5%BD%95%E4%B8%8B%E7%9A%84sources.list%20%E7%BB%88%E7%AB%AF%E8%BE%93%E5%85%A5%EF%BC%9Asudo%20nano,%E6%89%93%E5%BC%80%E7%BB%88%E7%AB%AF%EF%BC%9A%20%E8%BF%99%E9%87%8C%E6%88%91%E5%B7%B2%E7%BB%8F%E8%A3%85%E5%AE%8C%E4%BA%86%E3%80%82%20%E8%BF%99%E9%87%8C%E8%A6%81%E6%B3%A8%E6%84%8F%E4%BD%A0%E8%A3%85%E4%B9%8B%E5%89%8D%E4%B8%80%E5%AE%9A%E8%A6%81%E6%9C%89numpy%E8%BF%99%E4%B8%AA%E5%BA%93%E3%80%82%20%E4%B8%80%E8%88%AC%E6%83%85%E5%86%B5%E4%B8%8B%E5%88%B7%E5%AE%8C%E7%B3%BB%E7%BB%9F%E5%B0%B1%E6%9C%89%E4%BA%86%E3%80%82%20%E8%A3%85%E5%AE%8C%E4%B9%8B%E5%90%8E%E4%BD%A0%E5%8F%AF%E4%BB%A5%E7%BB%88%E7%AB%AF%E8%BE%93%E5%85%A5python3%E5%9B%9E%E8%BD%A6%E3%80%82%20%E8%BE%93%E5%85%A5import%20cv2%20%E7%84%B6%E5%90%8E%E5%9B%9E%E8%BD%A6%E3%80%82)
```bash
# 换源好之后更新数据和软件包
sudo apt-get update
sudo apt-get upgrade
```
### 安装摄像头
- [连接摄像头模块] 注意针脚有正反之别，直接看针脚来区分即可
- [打开摄像头模块] 打开树莓中，并重启。
- [测试是否可用] 
```bash
raspistill -o tmp.jpg #若能拍照，则ok。
```

## 环境
### opencv
- python2
```bash
sudo apt-get install libopencv-dev
sudo apt-get install python-opencv
```
- python3
```bash
sudo pip3  install opencv-python #安装之前需要有numpy库
# 若测试导入，提示缺失模块，测运行如下安装模块
sudo apt-get install libhdf5-dev
sudo apt-get install libatlas-base-dev
sudo apt-get install libjasper-dev
sudo apt-get install libqt4-test
sudo apt-get install libqtgui4
```
- 编译系列  
[参考文件](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)
- 测试
```bash 
python3 #打开python
import cv2 #导入库
cv2.__version__ # 查看版本号
```
## 常用服务
### ssh
- 管理面版打开
```bash
sudo raspi-config
# 选择 Interfacing Options-> SSH
```
- 终端自助打开
```bash
sudo systemctl start sshd #开始服务
sudo systemctl enable sshd #enable服务
```
### vnc
- 管理面版打开
```bash
sudo raspi-config
# 选择 Interfacing Options-> VNC
```
- 终端自助打开
```bash
sudo systemctl start vncserver  #开始服务
sudo systemctl enable vncserver #enable服务
```
### ftp
- 终端自助打开
```bash
# 配置文件位置/etc/vsftpd.conf ,默认通过本地用户访问
sudo systemctl start vncserver  #开始服务
sudo systemctl enable vncserver #enable服务
```
## 常用命令
### 网络管理
```bash
#注：[]表示变量，相应的替换即可
ip addr                                        # 显示当前ip地址和网口信息
ip link set [interface] up/down                # 设置网口开关
wpa_passphrase "[热点名称]" "[密码]" >[config] # 生成配置文件
wpa_supplicant -B -i [interface] -c [config]   # 通过配置文件连接wifi
dhclient [无线网口]                            # 无线网口获取ip
dhcpcd &                                       # 以太网口获取ip
```

### 服务管理
```bash
#注：以下命令在root用户下执行
systemctl start [server_name]     # 启动服务
systemctl stop [server_name]      # 停止服务
systemctl enable [server_name]    # enable服务
systemctl disenable [server_name] # disenable服务
systemctl status [server_name]    # 查看服务状态
```
