# react
- 描述
    - 动态构建用户界面的JavaScript库(只关注视图)
- 特点
    - 声明式编码
    - 组件化编码
    - React Native编写原生应用
    - 高效（diffing算法）
- 高效的原因
    - 使用虚拟（virtual）DOM，不总是直接操作页面真实DOM
    - DOM diffing 算法，最小化页面重绘

## 2.1 React基本使用
> 相关库：react.js 核心库 react-dom.js 操作DOM的扩展库、babel.min.js解析JSX语法转化为JS代码

- JSX
    - JavaScript XML
    - JS+XML本质是对React.createElement(component,props,..)方法的语法糖
    - 用来简化创建虚拟机react-dom
    - 基本语法规则：遇到<>标签开头以标签语法解析，遇到{ 语法开头以JS语法解析.
## 2.2 组件三大属性
- 1.state
- 理解
    - 1.state式组件对象最重要的属性，值是对象（可以包含多个key-value的组合）
    - 2.组件被称为"状态机"，通过更新组件的state来更新页面显示（重新渲染组件）
- 2.props （property s）
- 理解
    - 每个组件对象都会有属性。
    - 组件标签的所有属性保存再props中
- 作用
    - 通过标签从组件外向组件内传递变化的数据
    - 组件内不要修改props的数据
- 3.refs
## 2.3 组件的生命周期
## 2.4 虚拟DOM和DOM diff算法


