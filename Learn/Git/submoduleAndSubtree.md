> # subtree使用

作用大致相同，优势有
    - submodule不能再父库中修改子库代码，只能在子库中修改，是单向的
    - 没有直接删除子版本库的功能
subtree支持双向数据修改、官方推荐。

```bash
# 建立关联
git remote add subtree-origin git@github.com:AhuntSun/git_subtree_child.git
git remote show # 会显示两个远程地址了

```

## 仓库拆分
git subtree split

- simforge-studio-gateway
git subtree split -P simforge-gateway -b simforge-studio-gateway
git checkout simforge-studio-gateway
mkdir <new-repo>
git  init
git pull https://gitee.com/simforgecn/simforge-bak simforge-studio-gateway
git pull </path/to/big-repo> <name-of-new-branch>
- simforge-studio-appspace
git subtree split -P simforge-appspace -b simforge-studio-appspace
git checkout simforge-studio-appspace
mkdir simforge-studio-appspace
cd simforge-studio-appspace
git  init
git pull https://gitee.com/simforgecn/simforge-bak simforge-studio-appspace
git remote add origin https://gitee.com/simforgecn/simforge-studio-appspace.git
git push origin master
- simforge-studio-userportal
git subtree split -P simforge-userportal -b simforge-studio-userportal
git checkout simforge-studio-userportal
mkdir simforge-studio-userportal
cd simforge-studio-userportal
git  init
git pull https://gitee.com/simforgecn/simforge-bak simforge-studio-userportal
git remote add origin https://gitee.com/simforgecn/simforge-studio-userportal.git
git push origin master
- simforge-studio-opsportal
git subtree split -P simforge-opsportal -b simforge-studio-opsportal
git checkout simforge-studio-opsportal
mkdir simforge-studio-opsportal
cd simforge-studio-opsportal
git  init
git pull https://gitee.com/simforgecn/simforge-bak simforge-studio-opsportal
git remote add origin https://gitee.com/simforgecn/simforge-studio-opsportal.git
git push origin master
- simforge-studio-deploypackage
git subtree split -P simforge-deploypackage -b simforge-studio-deploypackage
git checkout simforge-studio-deploypackage
mkdir simforge-studio-deploypackage
cd simforge-studio-deploypackage
git  init
git pull https://gitee.com/simforgecn/simforge-bak simforge-studio-deploypackage
git remote add origin https://gitee.com/simforgecn/simforge-studio-deploypackage.git
git push origin master


## 父仓库管理
```bash
# 添加地址
git remote add subtree-origin git@github.com:AhuntSun/git_subtree_child.git
git remote show 
# 建立联系
git subtree add --prefix=subtree subtree-origin master --squash
# 其中的--prefix=subtree可以写成：--p subtree 或 --prefix subtree

# 更新子仓库内容
git subtree pull --prefix=subtree subtree-origin master --squash

git subtree push --prefix=subtree subtree-origin master

# simforge-portal
git remote add subtree-simforge-portal-back https://gitee.com/simforgecn/simforge-portal-back.git
git subtree add --prefix=simforge-portal-back subtree-simforge-portal-back master

git remote add subtree-simforge-portal-web https://gitee.com/simforgecn/simforge-portal-web.git

git remote add subtree-simforge-studio-userportal https://gitee.com/simforgecn/simforge-studio-userportal.git
```

[submodule and subtree 文档](https://juejin.cn/post/7077775905888124941)
