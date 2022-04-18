
# 做一个属于自己的代码格式

*转载请注明出处！*

---
> 千万人，有千万种活法，也有千万种行文风格，各有特色。那么我自己的呢？  
> 和朋友在讨论拿到别人的代码做的第一件是时候的时候，朋友的一句，先格式化。让我哭笑不得。  
> 看别人的代码很难受，说不上哪里难受，就是慢且难以言表。  
> 统一自己的代码风格，也统一所改变所浏览的代码风格  

## 确定一个自己喜欢的风格，或者接近目前代码的风格
```bash
pacman -S clang #这里使用的格式化工具是clang-format 包含在clang里面
# 选择一篇你日常写的代码，然后进行不同格式类型的格式化查看结果
clang-format [你的代码.cpp] --style=LLVM #style哪里可以选择其他
clang-format -h #查看用法，其中在style里面列出了几种类型
#LLVM, GNU, Google, Chromium, Microsoft, Mozilla, WebKit

#选定一种自己喜欢，或者接近自己目前代码形式的风格。
clang-format -style=LLVM -dump-config > .clang-format
#生成.clang-format文件，然后进入.clang-format文件中进行自己喜欢格式的微调。
mv .clang-format ~/.clang-format
#clang-format 在不指定style的时候默认会找当前目录下的.clang-format 文件，找不到会递归找父目录下的.clang-format文件。
```
## 在vim中配置
```bash
#安装autoformat插件，它提供一个框架，调用本机有的格式化插件去格式化
Plug 'vim-autoformat/vim-autoformat' 
#配置对C/C++的配置和设置快捷键
let g:formatdef_my_clang = '"clang-format"'
let g:formatters_cpp = ['my_clang']
let g:formatters_c = ['my_clang']
noremap <LEADER>bf :Autoformat<CR>
#其他语言的类似
```

---
**参考**：
- [vim-autoformat](https://140.82.112.4/github.com/vim-autoformat/vim-autoformat)
