# 面向对象编程
> 
## 1 内存的分区模型
- 程序在运行时，将内存大方向划分为4个分区
    - 代码区：函数体的二进制代码，由操作系统管理
    - 全局区：存放全局变量、静态变量、常量
    - 栈区：  由编译器自动分配释放，存放函数的参数值，局部变量等
    - 堆区：  由程序员分配和释放，若程序员不释放，程序结束时由系统回收♻️
> 意义：不同区域存放的数据，赋予不同的生命周期。

### 1.1 程序运行前
编译后，生成可执行文件，为执行前分为两个区域
- 代码区：
    - 存放cpu执行的机器指令
    - 代码区是共享的：频繁被执行的程序
    - 代码区是只读的：防止意外修改
- 全局区：
    - 全局变量和静态变量存放在此
    - 全局区包含了常量区，字符串常量和其他常量也存放在此，
    - 该区域结束后由操作系统释放
| 全局区                          | 不在全局区                     |
|---------------------------------|--------------------------------|
| 全局变量                        | 局部变量                       |
| 静态变量（static修饰）          |                                |
| 字符串常量                      |                                |
| const 修饰的全局变量（全局常量) | cont修饰的局部变量（局部常量） |

### 1.2 程序运行后
- 栈区：
    - 编译器自动分配释放，存放函数的参数值，局部变量
    - 不要返回局部变量的地址，栈区开辟的数据由编译器自动释放⭐️⭐️⭐️
- 堆区：
    - 由程序员分配和释放，若程序员不释放，程序结束时由系统回收♻️
    - c++中利用new在堆区开辟内存

### 1.3 new操作符
- 开辟空间 new
- 手动释放 delete
- syntax： new 数据类型
- 返回该类型所对应的指针

## 2 引用
> 给变量(内存）取了一个别名
> 把变量看成内存
- syntax： 数据类型 &别名= 原名；
```cpp
int &b=a;
```
### 引用的注意事项
- 引用必须初始化
- 初始化之后不能在修改
```cpp
int &b;//错误❌，必须初始化
int &b=a; 
int &b=c;//不能再次更改；
```
### 2.3 引用做函数参数
- 作用：函数传参时，可以利用引用修饰实参
- 可以简化指针修改实参

### 2.4 引用做函数返回值
- 函数的返回值是引用，函数调用可以作为左值 (不同编译器不一样，visual studio可以，gcc不行）
- 不能返回局部变量引用
### 2.5引用本质
- 本质 :cpp中内部实现的一个指针常量（int * const ref=&a)
        - 指向的地址不可以改变
        - 地址指向的值可以改变
### 2.6 常量引用
- 修饰形参，防止误操作
```cpp
void fun(const int &a);
```
## 函数提高
### 3.1函数的默认参数
- sytax：返回类型 函数名（参数=默认值）｛｝;
- 某个位置有了默认参数，这个位置之后的值都需要有默认参数
- 函数的声明有默认参数，函数实现就不能有默认参数；（声明和实现只能有一个有默认参数）
```cpp
int fun(int a,int b,int c=20){
    return a+b+c;
    }
void main(){
    int a;
    a=fun(a,a);
    }
```
### 3.2函数占位参数
函数形参列表可以有占位参数，用来占位，在调用时必须填补该位置
- sytax：返回类型 函数名（数据类型）｛｝
- 占位参数可以用默认参数
### 3.3函数重载
#### 3.3.1 概念 和条件
> 提高复用性
- 条件
    - 1函数名可以相同
    - 2同一个作用域下
    - 3函数参数不同or个数不同or顺序不同
#### 3.3.2函数重载的注意事项
- 参数避免相同

## 4类和对象 ⭐️⭐️⭐️
> 面向对象三特性：封装、继承、多态  
> 万物皆对象，对象有属性和行为
### 4.1封装
#### 4.1.1封装的意义
- 意义：
    - 将属性和行为作为一个整体
    - 将属性和行为加以权限控制

- sytax：class 类名｛ 访问权限： 属性/行为｝；
- 类中的属性和行为 统称 成员
    - 成员变量
    - 成员方法
- 访问权限
    - 公共权限 public     成员类内可以访问，类外也可以
    - 保护权限 protected   成员类内可以访问，类外不可以 儿子可以访问
    - 私有权限 private     成员类内可以访问，类外不可以 儿子不能访问

#### 4.1.2 struct 和class 区别
> 默认的访问权限不同
- struct 默认是 公共 public
- class  默认是 私有 private
#### 4.1.3成员属性设置为私有
- 优点
    - 将成员属性设置为私有，自己控制 ⭐️⭐️⭐️
    - 对于写，可以检测数据的有效性
#### 4.2 对象的初始化和清理
#### 4.2.1 构造函数和析构函数
- 构造函数： 创建对象时为对象成员属性赋值
    - 没有返回值，不用写void
    - 函数名与类名相同
    - 构造函数时可以有参数，可以发生重载
    - 自动调用，且只调用一次
- 析构函数：对象销毁前调用
    - 没有返回值，不写void
    - 函数名和类名相同 在名称前➕～
    - 不可以有参数，不可以发生重载
    - 在销毁前调用
#### 4.2.2 构造函数的分类和调用
- 两种分类方式：
    - 按参数
        - 有参构造和无参构造
    - 按类型
        - 普通构造和拷贝构造
- 三种调用方式
    - 括号法
    - 显示法
    - 隐式转换法
```cpp
void test(){
    Person p1; //默认调用
    Person p2(10); //括号调用
    Person p3(p1); //拷贝构造
    Person p1(); //错误，会被编译器认为是函数的声明
    Person p2= Person(10) //匿名对象，赋名为p2 ，只存活一行
    Person(p3) //❎ 不要拿拷贝构造创建 匿名对象，会重复，被认为是函数定义；
    Person p= 10 // == Person p(10);
}
```
#### 4.2.3 拷贝函数调用的时机
- 情况：
    - 使用一个已经创建完毕的对象
    - 值传递的方式给函数参数传值
    - 值方式返回局部对象
#### 4.2.4 构造函数的调用规则
- 一个类至少有三个函数
    - 默认构造函数
    - 默认析构函数
    - 默认拷贝函数（对属性值进行拷贝）
#### 4.2。5深拷贝和浅拷贝
- 一个经典问题
    - 浅拷贝：简单的赋值拷贝    //会造成，堆区内存重复释放
    - 深拷贝： 在堆区重新申请空间，进行拷贝操作
```cpp
Person(const Person &p){
        m_age=p.m_age;
        Height=new int(*p.Height);
        cout<<"拷贝数调用"<<endl;
    } //系统默认是浅拷贝，重新创建堆区内容的是深拷贝
    ~Person(){
        delete Height;
        cout<<"析构函数"<<endl;
    }
```
####4.2.6 初始化列表
```cpp
class Person{
 int m_A;
 int m_B;
 int m_C;

public:
    Person(int a,int b,int c):m_A(a),m_B(b),m_C(c){}

}
```
#### 4.2.7类对象作为类成员
```cpp
class A{}
class B
{
    A a;
}

//构造的时候先有A再有B；（构造函数）
//结束的时候先结束B，再结束A （析构函数）
```
#### 4.2.8 静态成员
>在成员前面加上static,称为静态成员
- 静态成员
    - 静态成员变量
    - 静态成员函数
        - 所有对象共享一个函数
        - 静态成员函数只能访问静态变量

### 4.3 C++对象模型和this指针
#### 4.3.1 成员变量和成员函数分开存储
>空对象 占用1个字节===》为了区分空对象占内存的位置  
>每一个空对象也有一个独一无二的空间  
>只有非静态变量占用对象内存，其他都不占
```cpp
#include <iostream>
#include <string>
using namespace std;
class Person{
    int m_a; //占用4个字节
    static int m_static; //不占用
    int  fun(){return 0;};//不占用
    //空对象占用1字节
};
void test(){
    Person p;
    cout<<sizeof(p)<<endl;
}
int main(){
    test();

    return 0;
}
```
#### 4.3.2 this指针
> this指针指向被调用的成员函数所属的对象
- this指针是每一个非静态成员函数内的一种指针
- 不用定义，直接使用
- 用途
    - 形参和实参相同时，this
    - 返回对象本身 
```cpp
#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    int age;
    Person(int age){
        this->age=age;
    };
    Person& PersonAddPerson(Person &p){ //这里需要引用传值，不加&的话会是浅拷贝
        this->age+=p.age;
        return *this;
    }
};
void test(){
    Person p(10);
    Person p2(20);
    p2.PersonAddPerson(p).PersonAddPerson(p).PersonAddPerson(p2);
    cout<<p2.age<<endl;
}
int main(){
    test();

    return 0;
}
```
#### 空指针访问成员函数

#### 4.3.4const修饰成员函数
- 常函数
    - 对象函数后面加const 成员变量不可修改，修饰的是this
```cpp
class Person{
public:
      int age;
    void showClassName() const 
    {
        cout<<"this is class name"<<endl;
        age=100; //报错，const修饰this，成员变量不可修改
    }
};
```
- mutable 关键字，添加后常成员变量可改
### 友元
- 生活中有客厅（public）卧室（private）
- 关键字friend
#### 4.4.1全局函数做友元
- 函数访问类中的私有成员
- 在类中声明函数
```cpp
class Buiding
{
    friend void goodguy(Buiding * buiding); //这样可以访问到m_bed_room
    friend class GodGuy;
    friend void GodGuy::visit();
public: 
    Buiding(){
        m_sitting_romm="sitting_room";
        m_bed_roon="bed_room ";
    }
    string m_sitting_romm;
private:
    string m_bed_roon;
};
```
#### 4.4.2 类做友元
- 类似全局函数做友元，在定义之后，GodGuy类可以在自身中访问

#### 4.4.2 成员函数做友元
- 类似全局函数做友元，在定义之后，GodGuy类中的函数友元可以在自身中访问

### 4.5运算符重载
- 对已有的运算符重新定义，赋予其另一种新功能，以适应不同的数据类型
#### 4。5.1加号运算符重载
```cpp
using namespace std;
class Person{

    public:
      int   m_A;
      int  m_B; //类内重载 相当于 p3=p1.operator+(p2);
//        Person operator+(Person &p){
//            Person temp;
//            temp.m_A=this->m_A+p.m_A;
//            temp.m_B=this->m_B+p.m_B;
//            return temp;
//        }
};
//全局重载，相当于p3=operator+(p1,p2);
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}
void test(){
    Person p1;
    p1.m_A=10;
    p1.m_B=20;
    Person p2;
    p2.m_A=10;
    p2.m_B=30;
    Person p3=p1+p2;
    cout<<p3.m_A<<endl;
    cout<<p3.m_B<<endl;

}
```
>内置的数据类型表达式不可以改变  
> 不要滥用运算符重载

#### 4.5.2左移运算符重载 
```cpp
class Person{
    public:
      int   m_A;
      int  m_B;
      void operator<<(ostream& out){ //类内实现的需要p在前
          cout<<m_A<<" "<<m_B<<endl;
      };
};

ostream& operator<<(ostream &out,Person &p){ //返回引用之后可以连续，链式编程
    cout<<p.m_A<<" "<<p.m_B<<endl;
    return out;
}
void test(){
    cout<<p3<<endl;
    p3<<cout;
}
int main(){
    test();
    return 0;
}
```
#### 4.5.3递增运算符重载
> 通过递增运算符  

```cpp
class MyInt{
    friend ostream& operator<<(ostream& out,MyInt i);
    public:
        MyInt& operator++(){ //前置递增
            m_int++;
            return *this;
        }
        MyInt operator++(int){//后置递增
            MyInt temp;
            temp.m_int=this->m_int;
            m_int++;
            return temp;
        }
    private:
        int m_int=0;
};
```
- 前置递增返回引用，后置递增返回值
#### 4.5.4赋值运算符号重载
```cpp
        Person& operator=(Person &p){
            if(this->m_age!=NULL){
                delete this->m_age;
                m_age=NULL;}
            this->m_age=new int(*p.m_age);
            return *this;
        }
```
- 系统自带的对象相等是浅拷贝，会造成堆区的重复释放，
- 返回本身，链式编程
#### 4.5.5关系运算符重载
- 对比类操作

#### 4.5.6函数调用符重载
- 仿函数 ：类像函数，写法不唯一
```cpp
class Add{
    public:
    int operator()(int a,int b){
        return a+b;
    }
};
int main(){
    Add add;
    int a=add(10,20);//仿函数
    cout<<Add()(10,20)<<endl; //匿名类，就只想使用一次这个功能
    cout<<a<<endl;
    return 0;
}
```
## 4.6继承
- 三大特性之一
- 是重点，不是难点
### 4.6.1继承的基础用法
- 减少重复、公共的代码
- 语法：class 子类 : 继承方式 父类
- 子类也成为派生类
- 父类也成为基类
### 4.6.2 继承方式
- 三种
    - 公共继承public
    - 保护继承protected
    - 私有继承private
```cpp
class base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
       
       //public 可以继承public的
       //protected 可
```
### 4.6.3继承中的对象模型
- 全部都继承，包括私有成员

### 4.6.4继承中的构造和析构顺序
- 构造函数 ：先base 再son
- 析构函数： 先son 再base
###　４．６．５继承同名成员处理方式
- 直接调用是调用到子类中的同名成员
- 子类中同名成员会隐藏掉父类中所有同名成员
```cpp
class base
{
public:
    int m_A;
    base(){
        m_A=100;
    }
};
class son :public base{
public:
    int m_A;
    son(){
        m_A=200;
    }
};
int main(){
    son s1;
    cout<<s1.m_A<<endl;
    //通过子类中的访问父类中同名成员需要加作用域
    cout<<s1.base::m_A<<endl;
return 0;
}
```
### 4.6.6继承中静态成员的处理方法
- 通过对象访问
- 加域访问
```cpp
 son s1;
 s1.func(10);
 son::base::func(10);
```
### 4.6.7 多继承语法
- 可以一个类继承多个类
- ｓｙｎｔａｘ：　class 子类　：继承方式: 父类１，继承方式：父类２.....
- 虚继承可以解决重复命名 virtual public base;
- 虚继承解决🔷菱形继承

## 4.7.1 多态
- 三大特性之一
    - 静态多态 ：函数重载，运算符重载都属于静态多态。
    - 动态多态: 在函数之前加virtual  之后的子类再实现就会变成它的
- 动态多态满足条件
    - 子类重写父类的虚函数。
    - 有继承关系
- 使用
    - 父类的指针或引用指向子类对象

### 4.7.2多态案例--计算器类
### 4.7.3存虚函数和抽象类
>父类中的纯虚函数是无意义的，需要靠子类来重写
- 用法 virtual 返回类型 函数名(参数列表)=0;
- 当类中有了纯虚函数，类也变成了抽象类
- 特点
    - 无实例化对象
    - 子类必须重写父类中的纯虚函数，否则也为抽象类
### 4.7.4多态案例二--制作饮品

### 4.7.5虚析构函数和纯虚析构
- 多态调用时，如果子类在堆区开辟空间，那么父类指针无法调用子类的析构代码
- 解决方法：将析构函数写成虚析构或者纯虚析构函数
    - 可以解决父类指针释放子类对象
    - 都需要有具体的函数实现
### 4.7.6多态案例--电脑组装


