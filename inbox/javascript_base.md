#javascript base

## 运行方式
```bash
- 内联：在html的标签内部直接写<script> </script>
- 外部：在html标签中写明路经 <script src=" "></script>
```
## 显示数据
- window.alert() 警告框
- document.write() 写入HTML文档
- innerHTML 写入HTML元素
- console.log()浏览器控制台输出

## 语法
- 字面量：固定值
    - Number (整数、小数、科学计数）
    - String （可单引号也可双引号）
    - Array　
    - Object
    - Function
```js
//Number
100
3.14
123e5
//String
"zhangsan"
'lisi'
//Array
[1,2,3,4,5]
//Object
{name:"zhangsan", age:18}
//Function
function myFunction(a,b){return a*b;}
```
- 变量：存储数据值，用var来定义，＝号来赋值
```js
var x length
x=5
length=6
```
>字面量是一个值，变量是一个名称
## 操作符

| type                 | example   | describ |
|----------------------|-----------|---------|
| 赋值、算术和位运算   | = + - * / |         |
| 条件、比较、逻辑运算 | == != > < |         |
```js
x=1+2;
y=3*4;
```
## 关键字

## 注释
- 单行注释：//
- 多行注释：/*  

## 数据类型
>数字、字符串、数组、对象
```js
var x=1;
var name="zhangsan";
var arr=["a","b","zhangsan","lisi"]
var person={name:"zhangsan", age:18}
 ```

## 变量作用域
- 全局
    - 常量：const x
    - 变量：（在块外定义）　var x
- 局部变量
    - 块变量｛｝:let x
    - 局部（块内）:var x


## 函数
>引用一个函数＝调用函数（执行函数内的语句）
```js
function myFunction(a*,b){
    return a+b;
 }
```
