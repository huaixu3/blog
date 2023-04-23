# electron 

## 主进程main
### 主进程通信
```javascript
//1.1主进程和渲染进程通信
//main 
ipcMain.on('a',(e,data)=>{
  console.log(data)
})
//render
ipcRenderer.send('a',123);

//1.2主进程和渲染进程通信,且回传
//main
ipcMain.on('a',(e,data)=>{
  console.log(data)
  e.sender.send('b',"bbbbb")
})
//render
const electron = require('electron')
const ipc = electron.ipcRenderer
ipc.on('b', (e, data) => {
    console.log(data)
})

// 1.3向渲染进程广播发送
//main
ipcMain.on('a', (e, data) => {
  console.log(data)
  webContents.getAllWebContents().forEach(it => {
    it.send('b', 'bbbbbb')
  })
})

// 1.4 渲染进程之间通信
//render
ipc.sendTo(1,'b','lllllllllllllllllll')
//给webContents 1的发送

// 1.5 有返回值的通信
//main
ipcMain.handle('echo',(e,data)=>{
  return data;
})
//render
ipc.invoke('echo', '333').then(res => { console.log(res) })


```
## 渲染进程render（多个）
- WebContents _每一个渲染窗口内容_
