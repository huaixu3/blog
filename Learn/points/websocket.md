```bash
// 创建WebSocket连接.
const socket = new WebSocket('ws://localhost:8080');
 
// 连接成功触发
socket.addEventListener('open', function (event) {
    socket.send('Hello Server!');
});
 
// 监听消息
socket.addEventListener('message', function (event) {
    console.log('Message from server ', event.data);
});
```

```bash
#方法、两个
close()
send()
#事件
close
error
message
open

```

```mermaid
graph LR
a(websocket) --> b(tcp)
c(http) -->b

d(socket.io)-->a
