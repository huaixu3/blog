# 使用docker在本地搭建jekyll服务调试
> 作者使用的本机是manjaro，在安装启动jekyll调试过程中一直报错，无奈头发有点多，所以选择偷懒的方式  
> 使用docker在本地搭建jekyll服务调试，以避免依赖等错误

## 过程
```bash
docker pull ubuntu
docker run -it ubuntu -v /home/[user_name]/[jekyll_project]:/home/mount ubuntu
#以下在ubuntu镜像中
apt-get -qqy update #更新源
sudo apt-get -qqy install ruby-full build-essential zlib1g-dev #Install Ruby and other prerequisites:
echo '# Install Ruby Gems to ~/gems' >> ~/.bashrc #add environment variables 
echo 'export GEM_HOME="$HOME/gems"' >> ~/.bashrc
echo 'export PATH="$HOME/gems/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc 
gem install jekyll bundler #Finally, install Jekyll and Bundler:

jekyll new my-awesome-site #quick start
cd my-awesome-site
bundle exec jekyll serve
# => Now browse to http://localhost:4000
# 以上来自jekyll官方的安装过程
#以上过程之后访问主机的localhost：4000还是dockerip:4000 都是无法成功的。
#原因是前者没有在启动时映射端口，后者防火墙默认屏蔽除本机以外的访问。
#修改如下
#1.
docker run -it ubuntu -p 4000:4000 -v /home/[user_name]/[jekyll_project]:/home/mount ubuntu
#通过映射端口然后访问localhost:4000可以访问
#2.
bundle exec jekyll serve --host=0.0.0.0 #在docker容器中设置任何ip地址可访问

# 最后保存镜像，以供以后使用。在本机中
docker commit [container_name] jekyll
#下一次本地调试时
docker run -it ubuntu -p 4000:4000 -v /home/[user_name]/[jekyll_project]:/home/mount jekyll
cd /home/mount
jekyll s --host=0.0.0.0
#都需要添加-host参数以让其他ip可以访问
```
