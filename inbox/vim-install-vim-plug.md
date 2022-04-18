# 安装coc.nvim (在github不能用的前提下）
使用gitee

看  现在没有文件  所以找不到命令

刚刚搞错了 大概就是下载这个文件jjjjjj
换掉这个地址

然后PlugInstall 生效就能下载好了
大概如此
## 安装vim-plug
    - 从远端安装
    - 从本地安装 (在github难以上去的替代方法）
    **本质：把plug.vim文件放在~/.vim/autoload目录下** 

## 安装coc.nvim
在~/.vimrc中写入，如下的，并把地址相应的改了，从gitee下载
```bash
call plug#begin('~/.vim/plugged')
Plug 'neoclide/coc.nvim', {'branch': 'release'}
call plug#end()
```

