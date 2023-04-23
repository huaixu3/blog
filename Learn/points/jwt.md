## 构成

- header
- payload
- signature
  
- header 存放两部分信息
    - 类型声明
    - 声明加密码算法
```json
{
    "typ":"JWT",
    "alg":"HS256"
}
```
然后进行base64编码
`eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9`
- payload
    - 标准注册中的声明
    - 公共的声明
    - 私有的声明

- 标准中的注册声明（建议但不强制使用）
    - iss：jwt签发者
    - sub：jwt所面向的用户
    - aud：接收jwt的一方
    - exp：jwt的过期事件，这个过期时间必须大于签发时间
    - nbf：定义什么时间之前，该jwt都是不可用的
    - iat: jwt的签发时间
    - jti：jwt的唯一身份标识，主要用作一次性token，从而回避重放攻击
- 公共的声明
    - 可以添加任何信息，一般为用户的相关信息和业务的必要信息（该部分可以在客户端解密）
- 私有的声明
    - 双方共同定义的声明
```json
{
    "sub":"12345",
    "name":"zhangsan",
    "admin":true
}
```
然后将其进行base64编码
`eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWV9`

- signature 签证信息，由三部分组成
    - header（base64后的）
    - payload（base64后的）
    - secret
```js
// javascript
var encodedString = base64UrlEncode(header) + '.' + base64UrlEncode(payload);

var signature = HMACSHA256(encodedString, 'secret'); // TJVA95OrM7E2cBab30RMHrHDcEfxjoYZgeFONFh7HgQ
```
