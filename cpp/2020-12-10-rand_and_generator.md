# C++中的随机数

## 实例
```cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
    unsigned seed;
    seed=time(0);
    srand(seed);
    cout << rand() << endl;
    return 0;
}
```

## rand（）
> 生成并返回一个伪随机数列,0-MAX中的一个值
- sytax ： int = rand（）;
- 库：cstdlib
```cpp
cout<<rand()<<endl;
```
## srand()
> seed and random num generator,种子数生成器
- syntax: void srand(unsigned seed);
- 每个伪随机序列都有一个起始值（种子）。
```cpp
unsigned seed;
srand(seed)
cout<<rand()<<endl; //这样输出的值便会和上面的有差别
```
## time()
>返回当前时间
- sytax：time_t time(time_t *__timer)
- 库：ctime
```cpp
cout<<time(0)<<endl;
cout<<time(NULL)<<endl;
```

