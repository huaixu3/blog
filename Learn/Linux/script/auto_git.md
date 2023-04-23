# git自动同步
## 每30分钟拉取一次仓库更新
`*/30 * * * * /path/pull.sh`
```bash
#!/bin/sh 
#/path/pull.sh
export LANG=zh_CN.UTF-8 
cd /path/blog 
unset GIT_DIR 
git stash 
git pull origin master
```
## 每天中午/下班自动保存并push
`0 12,18 * * * /path/push.sh`
`ssh://git@xxxx.com:222/username/repo.git` _如果默认端口不是22，则需要改变书写格式_ 
`git@xxx.com/username/repo.git` _如果是22端口的情况_ 

```bash
#!/bin/sh
#/path/pull.sh
dd=`date +%Y%m%d-%H:%M`
export LANG=zh_CN.UTF-8
unset GIT_DIR
cd /path/repo
git pull origin master
git add *
git commit -m "$dd backup"
git push origin master
```
