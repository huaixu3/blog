# 检查磁盘使用情况

## 若超过限额，则调用删除命令(删除临时文件，以避免死机)，邮件通知相应负责人
```bash
#!/bin/sh
# check disk usage
# if over ,report and delete /tmp dictionary file ol*
#
#
quota=60 # default 60 percent
disk="/dev/" # default /dev/* disk

use=$(df -h |grep $disk |awk '{print $5}' |sed 's/%//' |tr '\n' ',' |sed 's/.$//')
IFS=,
diskArr=($use)
for ((i=0;i<${#diskArr[@]};i++))
do
    echo value: ${diskArr[$i]}
    if [ ${diskArr[$i]} -gt $quota ]
    then
        title=$(df -h |awk "NR==1{print}")
        spe=$(df -h |grep "/dev/" | awk "NR==$(($i+1)){print}")
        echo -e "SomeThingWrong \n $title \n $spe" | mail -s "hasWrong" mail@xx.com
        sh /path/to/rmSomeFile.sh
    fi
done
```
