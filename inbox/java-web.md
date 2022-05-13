# java web

## web服务器
### 2.1 技术
ASP:
php:

JSP/Servlet：
    B/S:浏览器和服务器
    C/S:客户端和服务器
> sun b/s 
> 语法像asp-》jsp

### 2.2 web服务器
> 一种被动的操作 服务，相应用户的请求
- IIS 
    _ 微软的，asp 微软中自带_

- Tomcat
    - JSP页面和Servlet，

### Tomcat

### Http
- 简单的请求-相应协议，通常运行在TCP之上
    - 文本：html 字符串
    - 超文本：图片、音乐、视频、定位
    - 80
- Https：安全的
    - 443
#### 4.2两个时代
- http1.0
    - 只能获得一个web资源
- http1.1
    - 与服务器连接之后，可以获得多个web资源

#### 4.3http请求
- 客户端- 发请求（request） --服务器
```bash
Request URL
```
1.请求行
- 请求方式：GET、Post
    - get :携带信息少，但高效
    - post：携带信息无限制，安全，不会再url显示内容，但不高效
2.请求头
#### 4.4 响应
- 服务器- 回复--客户端

- 编码：gbk utf-8 gb2312 iso8859
- 响应体：
    - HOST、主机
    - refresh、告诉客户端多久刷新一次
    - location 重定位

2.响应状态码
200：请求成功
3xx：重定向
4xx：资源不存在
500：服务器错误，502网关错误

### Maven
1.javaweb需要大量的jar包，我们手动去导入
#### 5.1maven项目架构管理配置
核心思想：约定大于配置
5.2 阿里云镜像
5.3 本地仓库
