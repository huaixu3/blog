# git base 

## start
    - git init
          创建一个仓库
    
## file
    - git add
          1.添加一个文件成索引状态
          2.把修改过的文件提交到暂存区
    - git rm
          - 移除一个文件的索引状态
    - git diff
          - 比较源文件 和目标文件的修改
          
    - git log
          - 显示提交状态 方式较多，format可以定制
          
    - git commit
          - 把暂存区的文件提交到git仓库里面
          - m选项添加message

## branch(git 杀手锏）
    - git branch
          - 后面跟分支名 新增一个分支（其实是添加一个指针） 
    - git checkout
    - git checkout -b
          - 切换到一个分支里面区 b选项可以新建一个分支
    - git merge
          - 合并两个分支


## file status
| 索引态   | -      |
|----------|--------|
|          | 修改态 |
|          | 暂存态 |
|          | 提交态 |
| 未索引态 |        |

## git
| work area | git stage | git repository |  
|-----------|-----------|----------------|
