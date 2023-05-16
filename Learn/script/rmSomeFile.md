# 删除一些文件
## 删除一些文件并写入日志
```bash
#!/bin/sh

# 递归删除指定目录下的指定文件
#指定目录
targetDir='/path/to/targert/'
#指定名字,可以正则匹配，如ol*
targetName=".somefile"
dd=`date +%Y%m%d-%H:%M`
#文件(1)还是文件夹(2)
isFile=1
if  [ $isFile -eq 1 ]
then # 文件1
        echo $dd >> rmFileLog.txt
        find $targetDir -name $targetName -type f -print >>rmFileLog.txt
        find $targetDir -name $targetName -type f -print -exec rm -f {} \;
else # 文件夹2
        find $targetDir -name $targetName -type d -print >>rmFileLog.txt
        find $targetDir -name $targetName -type d -print -exec rm -rf {} \;
fi
```
