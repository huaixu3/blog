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
[submodule and subtree 文档](https://juejin.cn/post/7077775905888124941)
