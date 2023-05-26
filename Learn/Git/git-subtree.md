# subtree 
> # subtree 仓库的拆分和管理
## submodule和subtree 区别
作用大致相同，优势有
    - submodule不能再父库中修改子库代码，只能在子库中修改，是单向的
    - 没有直接删除子版本库的功能
subtree支持双向数据修改、官方推荐。

## 仓库拆分
```sh
git subtree split
#mhyt-studio-gateway
git subtree split -P mhyt-gateway -b mhyt-studio-gateway
git checkout mhyt-studio-gateway
mkdir mhyt-studio-gateway
git  init
git pull https://gitee.com/mhytfun/mhyt-bak mhyt-studio-gateway
# mhyt-studio-appspace
git subtree split -P mhyt-appspace -b mhyt-studio-appspace
git checkout mhyt-studio-appspace
mkdir mhyt-studio-appspace
cd mhyt-studio-appspace
git  init
git pull https://gitee.com/mhytfun/mhyt-bak mhyt-studio-appspace
git remote add origin https://gitee.com/mhytfun/mhyt-studio-appspace.git
git push origin master
# mhyt-studio-userportal
git subtree split -P mhyt-userportal -b mhyt-studio-userportal
git checkout mhyt-studio-userportal
mkdir mhyt-studio-userportal
cd mhyt-studio-userportal
git  init
git pull https://gitee.com/mhytfun/mhyt-bak mhyt-studio-userportal
git remote add origin https://gitee.com/mhytfun/mhyt-studio-userportal.git
git push origin master
```

## 父仓库管理
```bash
# 添加地址
git remote add subtree-origin git@github.com:huaixu3/git_subtree_child.git
git remote show 
# 建立联系
git subtree add --prefix=subtree subtree-origin master --squash
# 其中的--prefix=subtree可以写成：--p subtree 或 --prefix subtree
# 更新/推送子仓库内容
git subtree pull --prefix=subtree subtree-origin master --squash
git subtree push --prefix=subtree subtree-origin master

# eg :mhyt-portal
# 添加仓库源地址
git remote add subtree-mhyt-portal-back https://gitee.com/mhytfun/mhyt-portal-back.git
git remote add subtree-mhyt-portal-web https://gitee.com/mhytfun/mhyt-portal-web.git
# 添加进仓库中，--squash参数要么一直都有，或者都不用。不然会错乱。
# 父仓库不更新推送给子仓库，只做汇总处理的话，加不加都可
git subtree add --prefix=mhyt-portal-back subtree-mhyt-portal-back master
git subtree add --prefix=mhyt-portal-web  subtree-mhyt-portal-web  master
```

[submodule and subtree 文档](https://juejin.cn/post/7077775905888124941)
