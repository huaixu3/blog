## operate computer as vim
![keychron-k6](https://img-blog.csdnimg.cn/20210421235012709.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70)
> 在收到瑶哥键盘的一个月后，开发了一套类vim快捷键,适应了这种懒模式，特此记录一波  
> 在使用dwm的途中，手指越来越不想离开主键位，去够键盘的一些边角区域  
> 在有了K6之后，这样的情况扩大了，实在不想去够几个重要且有边角的键（esc，方向键，fn1，2）  
> 于是设计了这一套键位，让整个电脑的操作逻辑都vim化了。  

**思路大概如下**  
*启发于vim的使用*

## 四种模式
   * 普通模式（normal mode）
       - [key] 的键入模式（所见即所得，键入a就是a  
   * 扩展模式（extension mode）
       - shift+[key] 的模式，这个映射没有修改，一般键入一些字符等等（和正常的一样）
   * 视图模式（view mode）
       - Mod+[key] 的键入，这里使用的是dwm对视图的管理，我这里mod键设置的是Alt  
        eg:  
        | 键位            | 功能               |
        |-----------------|--------------------|
        | Mod+shift+enter | 创建终端           |
        | Mod+c           | 打开chromium浏览器 |
        | Mod+m           | 全屏/平铺/浮动模式 |
        | Mod+j/k         | 窗口的上下切换     |
        ....这里用的是dwm的，不作展开  

   * 导航模式（navigation mode）
       - Swith+[key] 的键入，是本文的重点，使用xmodmap来修改键位映射，多出了一种模式，更懒的摆放双手，
        Swith键设置的是Caps_lock键，原先的Caps_lock 变成shift+caps_lock
  
        | 键位                            | 功能                                  |
        |---------------------------------|---------------------------------------|
        | Swith + h/j/k/l                 | 方向键左/下/上/右                     |
        | Swith + 1/2/3/4/5/6/7/8/9/0/-/= | 对应F1-F12                            |
        | Swith = esc                     | Switch键单点映射esc键，组合是导航功能 |

        优势：创新主要在四个方向键的绑定和单点映射esc键哪里，真的是越用越爽，很多时候都会忘了左上角的esc键和右下角的方向键。作为一个vimer，在vim当中可以不用切换普通模式达到轻度移动，和快速的esc键有了很好的体验
        

## 对于键盘的一些小思考
- 于我看来，以前的普通款的108键盘已经很少看到（这句话之适用于自己身边的人）
- 大多买键盘偏好于87键/79键，去掉了数字键和一些使用频率十分少的功能键，感觉除了便捷一方面之外，可能还有不愿意突然够老远去按数字键，所以首当其冲的它被砍掉了
- 有少一部分人选择了61/68键，我属于其中一员，于我而言，这带给我的最大变化不是携带便捷，而是一种手不离开主键位的偷懒  

## enjoy vim
[xmodmap参考](https://wiki.archlinux.org/index.php/Xmodmap)  
[xcape参考](https://wiki.archlinux.org/index.php/Xorg/Keyboard_configuration#One-click_key_functions)  
<<<<<<< HEAD:blog/posts_bak/think_life/2021-04-21-keybord-vim.md
![scre](https://img-blog.csdnimg.cn/20210421235127879.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0Nzk3MDg2,size_16,color_FFFFFF,t_70)
