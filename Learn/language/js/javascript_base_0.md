# javascript base

## 0.hello world
```javascript
console.log("hello world")
```
## 0.1 注释
```javascript
//这是单行注释
/* 这是
   多行注释
*/
/* 也可以
*  这样
*/
```
## 0.2 输入输出
```javascript
console.log("这是输出到终端")
```
## 1.1 变量
```javascript
var x=5;
var y=5+x;
var str="string";

// let and const
function myFunction{
    let a=5 // 局部变量，只在这个代码块生效
}
const PI= 3.14 //常量，创建之后不能再更改
```
## 1.2 常量
```javascript
const TIP = "I'am const varible" 
```
## 1.3 关键字
```javascript
// 同样的几个，略。
```
## 1.3 标识符(变量、常量名)
_1.避开关键字_
_2.推荐驼峰命名myVar_
_3.全局变量常量全大写PI_

## 2 数据类型
> 基本数据类型：String Number Boolean Null Undefined Symbol  
> 引用数据类型（对象类型）：对象（Object) 、数组（Array）、函数（Function）、正则（RegExp）、日期（Date）
```javascript
var x; // Undefined
var y=5; //Number
var z="zhangsan" //String

typeof(x) // 查看类型，返回Undefined
typeof(y) // 查看类型，返回Number

var x=true;
var y=false; //Boolean

var cars=new Array();
cars[0]="a";
cars[1]="b";
cars[2]="c"; //Array
var cars=new Array("a","b","c"); //Array
var cars=["a","b","c"]; //Array

var person={
    name:"zhangsan",
    age:18,
    id:1
}// Object 对象
name= person.name;
name=person["name"]; //两种寻址方式
```

##  3.运算符
> 算术运算符、赋值运算符、比较运算符、逻辑运算符
## 3.1 算术运算符
| 运算符 | 例子  | 描述         |
|--------|-------|--------------|
| +      | y=x+2 | 加           |
| -      | y=x-2 | 减           |
| *      | y=x*2 | 乘           |
| /      | y=x/2 | 除           |
| %      | y=x%2 | 取模（余数） |
| ++     | y++   | 自增         |
| --     | y--   | 自减         |
## 3.2 赋值运算符
| 运算符 | 例子 | 描述     |
|--------|------|----------|
| =      | y=2  | 直接赋值 |
| +=     | y+=2 | 自增赋值 |
| -=     | y-=2 | 自减赋值 |
| *=     | y*=2 | 自乘赋值 |
| /=     | y/=2 | 自除赋值 |
| %=     | y%=2 | 取余赋值 |

```javascript
var str="str1";
var str1="str2";
var str2= str + str1 ;//str1 str2 字符串拼接
```
## 3.3 比较运算符
| 运算符 | 例子        | 描述                                  |
|--------|-------------|---------------------------------------|
| ==     | y=1;y==2    | 等于，返回false                       |
| ===    | y="2";y===2 | 绝对等于（值和类型均相等），返回false |
| !=     | y=1;y!=2    | 不等于，返回true                      |
| !==    | y="2";y!==2 | 不绝对等于，返回true                  |
| >      | y=1;y>2     | 大于，返回false                       |
| <      | y=1;y<2     | 小于，返回true                        |
| >=     | y=1;y>=2    | 大于等于，放回false                   |
| <=     | y=1;y<=2    | 小于等于，返回true                    |
## 3.4 逻辑运算符
| 运算符 | 例子                 | 描述                           |
| &&     | y=2; （y>1 &&y<10）  | and,并，返回true               |
| \\     | y=0; （y>1 \\ y<10） | or,或，返回true,（注：为竖线） |
| !      | y=3; !(y==2)         | not,取反，返回true             |

##  4 程序结构
> 选择结构：if、 三目、switch、
> 循环结构：for 、while、do..while
> 跳转语句：break 、continue

## 4.1 选择结构
```javascript
//if
if(time<20){
    console.log("good day")
}else if(time<22){
    console.log("oh no")
}else{
    console.log("no")
}
// switch
var d=new Date().getDay();
switch(d){
    case 0: console.log("sunday");break;
    case 1: console.log("monday");break;
    case 2: console.log("tuesday");break;
    default: console.log("aha");
}
// 三目
x=time<20?"good day":"oh no";
```
## 循环结构
```javascript
//for
cars=["a","b","c"]
for(var i=0;i<cars.length;i++){
    console.log(cars[i]);
}
//while
var i=0;
while(i<3){
    console.log(cars[i]);
    i++;
}
//do while
do{
    console.log(cars[i]);
    i++;
}while(i<2);
```
## 跳转语句
> break : 跳出当前循环  
> continue ：跳过本次迭代  

## 5 数组
## 6 函数
```javascript
function mufunc(a,b){
    return a+b;
}

