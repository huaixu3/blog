
 1.函数式组件没有生命周期
 2.函数组件没有this
 3.函数组件没有state状态

    - 生命周期：创建、更新、销毁
    - created、update、destoryed

    hooks
        - React官方提供的hook 
        - 开发人员自定义的hook

React hook : useState
            useEffect
```javascript
//created:
// ajax init
useEffect(()=>{
    console.log("created")
},[])
//update:
useEffect(()=>{
    console.log("num1 update")
},[num1])
//destoryed
useEffect(()=>{
    return ()=>{
        console.log("destoryed")
    }
})
```

## 
受控组件使用state或useState来更新它的值。
表单元素为受控组件：input

