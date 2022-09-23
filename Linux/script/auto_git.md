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
`*/30 * * * * /path/push.sh`
```bash
#!/bin/sh 
#/path/pull.sh
dd=`date +%Y%m%d-%H:%M`
export LANG=zh_CN.UTF-8 
unset GIT_DIR 
cd /path/blog 
git add *
git commit -m "$dd backup"
git pull origin master
```

