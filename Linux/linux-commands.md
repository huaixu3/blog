# commands
```bash
# 文件权限备份与恢复
getfacl -R /directoryOrFile > permis.facl #备份目录或文件的权限到permis.facl
setfacl --restore=permis.facl #从permis.facl文件恢复文件中记录的权限信息
```
