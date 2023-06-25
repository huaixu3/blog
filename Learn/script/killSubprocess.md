# 杀死子进程及衍生进程

```bash
#!/bin/bash 
# 查找父进程
parentId=$(ps -ef | grep "process$" | grep -v grep | awk '$3==1{print $2}')
#echo $parentId
# 查看子进程数组中排除某些子进程
cbpsId=$(ps -ef | grep "subpId_exatra$" | grep -v grep | awk '{print $2}')
#echo "cbps Id " 
#echo $cbpsId

# 查看并记录杀掉的子进程号
subpId=$(pgrep -P $parentId |grep -v $cbpsId )
# 杀死
killsubpId=$(pgrep -P $parentId |grep -v $cbpsId | xargs pkill -P)

# 记录时间及杀死的子进程号
dd=`date +%Y%m%d-%H:%M`
echo $dd >> killSubprocessLog.txt
echo $subpId >> killSubprocessLog.txt
```
