## 环境
> 服务器系统 centos-8  
> python3

```bash
pip3 install jupyter
jupyter notebook --generate-config  # 这里推荐重新创建非root用户下

python3
```
## 配置
```python3
from notebook.auth import passwd
passwd() #然后输入你想要设置的密码，并记录下生成的密钥
```
```bash
nvim ～/.jupyter/jupyter_notebook_config.py  
c.NotebookApp.ip = '*' #可以访问的ip，*为所有
c.NotebookApp.open_browser = False #是否打开浏览器
c.NotebookApp.notebook_dir = '/home/[user]/jupyter' #这里推荐在所在目录下创建一个目录来放
c.NotebookApp.port = 8888 #监听的端口，默认是8888
c.NotebookApp.password = '[*]'  #[*]中替换上面的密钥
```
## 运行
```bash
jupyter notebook & #后台运行。
#在阿里云控制端中修改安全组访问（开放相应的端口）即可访问
#在浏览器中中输入
# ip：8888   
#以访问
```
## 参考
[参考博客](https://blog.csdn.net/feilong_csdn/article/details/90677233)
