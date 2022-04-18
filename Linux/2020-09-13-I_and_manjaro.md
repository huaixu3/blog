>古有 工欲善其事 必先利其器
>今有  打造一个漂亮  快捷的环境 使自己越看越想看自己的电脑

## 选择的原因
刚开始接触vim的时候，一直想吐槽。咋会有这么繁琐且恶心的编辑器？友好点它不行吗？但其实知道了：q是退出之后i是插入之后，好像也基本能用了，只是速度极其缓慢。于是便有了其他快捷键。感觉就是，起点很低，或者说就只是个单纯的编辑器，但没有上限，甚至可以打造了媲美IDE。  
但，keep it simple，stupid。这样挺好  
久而久之。当使用到其他编辑器，遇到机械性处理时，总不免想到，这如果放在vim下，那可就不用重复性机械运动了啊。  
也许是喜欢kiss（keep it simple，stupid）理念的原因，或许是对GNU计划的倾佩，又或许是对自己简单骚动。  
所以打造一个自己大概知道它的环境。  

## 选择manjaro的原因
首当其冲的当然是菜啊，如果能优秀一些，直接上arch，所有的都自己配置一顿。但认清自己的菜之后，还是使用些较为友好的。
#### 对Linux内核的思考
linux衍生出那么多的发行版，  
	- ubuntu 使用的包管理器是apt，使用的桌面是gnome  
	- centos使用的包管理器是yum，使用的桌面是xfce（可选，作为服务器一般没有，作为个人使用我装过xfce，因为耗资源少，捂脸）  
	- deepin使用apt，使用的桌面是深度自己的  
	- manjaro使用的包管理器是pacman，使用的桌面可选。（同上）  
为什么他们都叫linux系统，但许多软件并不通用呢？  
我的理解是，linux是微内核，也就是只有内核层次是linux，其余的包管理器，桌面这些可作为服务的安装上去，供自己选择，这或许就是自由的原因把。与此相对的是Windows，打开之后包管理器，桌面，等都是已有的，不是自己可供选择的。  
	包管理器是基本的，提供一个给其他软件运行的环境和管理，所以得安装。桌面是一个和shell（外壳）和内核对话，不要桌面得话其实也行，直接进最初黑漆漆得终端也行，不过这个shell真的太黑了，缺乏必要得美感。  
	图形可视化的shell其实除了我们日常最常见的桌面，还有一种只保留最基本功能的，也就是窗口管理器，功能非常的少，不像任一桌面一样丰富与健全，但也许这也是它的优点，没啥功能，所以你能一下就知道看到它的所有，（捂脸）简单，但也不简单  
#### i3+alacritty+chrome+ranger+zsh+vim
废话那么多，开始进入正题。
* 底层用pacman包管理器，shell是可视化（我不是那种活在黑漆漆的终端下的人）
* 可视化shell使用窗口管理器i3（为啥不叫桌面呢？因为虽然也是可视化的图形界面，但是在太简单了，就只有窗口，没事，够简单）
* 有了i3这图形shell之后，主要使用的就是终端和浏览器
* 浏览器使用chrome，终端使用alacritty，软件使用终端生态下的软件
* 比如文件管理器ranger
* shell语言zsh
* 编辑器vim
他们之间的逻辑关系大概如下![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913204608129.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
附上几张现在的桌面，渲染器使用的是picom。

- i3本尊
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913204820296.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
* alacritty本尊
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913204953330.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
* alacritty+chrome 
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913205105899.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
* alacritty+ranger

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913205219574.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
* alacritty+vim
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913205417327.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
* alacritty+vim+ranger

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200913205536368.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70#pic_center)
##  结语
生活很大，但大抵使用的好像也没几个软件 ，简单些，便捷些。
