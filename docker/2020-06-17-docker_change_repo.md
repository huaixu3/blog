## ==docker换仓库==
```bash
cd /etc/docker/daemon.json
vim daemon.json
#vim  中输入
{
	“registry-mirrors”:[“https:****”]
	}
```
国内的几个源：
- Docker 官方中国区：https://registry.docker-cn.com
 - 网易：http://hub-mirror.c.163.com
- 中国科技大学：https://docker.mirrors.ustc.edu.cn
- 阿里云：https://y0qd3iq.mirror.aliyuncs.com

## ==重启服务==
```bash
systemctl daemon-reload #重载入daemom
systemctl restart docker #重新启动docker
docker info |grep Mirros -A 1 #查看换源是否成功
```
### *也许会发生的错误*
重启不了，使用systemctl status docker 看到错误时
```bash
Job for docker.service failed because the control process exited with error code.
```
估计是换源的时候daemon的配置文件有错误。**注意大小写，符号，最外面有一个花括号**
之后继续尝试 *重启服务*


## 一些思考
>配置文件一般在/etc目录下（和服务有关的，还有apt的也是在这里，好像yum也是）
>配置文件一般在个人home目录下的隐藏目录\隐藏文件（个人特色的，例如vim的.vimrc 和pip的 ~/.pip/pip.conf)
>个人感觉区别在于前者是更替电脑的某些配置（需要sudo才能使用）
>后者在于配置个人用户的偏好设置，
