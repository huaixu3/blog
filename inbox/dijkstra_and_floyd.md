# dijkstra and floyd

| name           | dijkstra                            | floyd                                  |
|----------------|-------------------------------------|----------------------------------------|
| goal           | v0 到v1,v2,v3...vn的最短长度d和路经 | 集合（v0，v1...vn任意两点间的最短长度d |
| 消耗           | time: O(n).space: S(3n)             | time:O(n^3).space :S(n^2)              |
| data_structure | S[n]={1:已检测；0:未检测}           | A^k[n][n]={v[i]到v[j]的距离            |
|                | dist[n]=v0到v1,v2,v3的最短长度      |                                        |
|                | path[n]{-1:初始节点;其他:其前驱节点 |                                        |
  



