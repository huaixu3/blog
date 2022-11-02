# nodejs

>轻内核：这个平台功能本身不提供功能  
>JS=ECMAScript+DOM+BOM  
>node运行的是es  

roadmap:javascript + 内置库（fs，path，http）+第三方库（express+mysql）

## 基础内置模块
> fs 文件系统模块
> path 路径模块
> http 模块

### fs
```javascript
const fs=require('fs') //载入模块
//查看文件
fs.readFile("./test.txt",'utf8',function(err,data){
    if(err){
        return console.log(err.message)
    }
    console.log(data)
})
//写入文件
fs.writeFile('./test.txt',"hello nodejs",function(err) {
    if(err){
        return console.log(err)
    }
    console.log("successful");

})
```
## path
```javascript
const path=require('path')

// 路径拼接
const pathStr=path.join(__dirname,'/test.txt')
console.log(pathStr)
//获取文件名字
var name=path.basename(pathStr)
console.log(name)
//获取文件名字,不带后缀名
var nameWithoutExt=path.basename(pathStr,'.txt')
console.log(nameWithoutExt)
//获取文件后缀名
var nameExt=path.extname(pathStr)
console.log(nameExt)
```
## http
```javascript
const http=require('http')

//创建一个服务器
const server=http.createServer()
//绑定方法
server.on('request',(req,res)=>{
   console.log("visit") 
    res.end("hello ")
})
//绑定监听端口
server.listen(80,()=>{
    console.log("http has running 80")
})
```

