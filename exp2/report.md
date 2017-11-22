# 实验二-实验报告

## 编译环境

- 编译器：gcc v6.3.0
- 编辑器：VS Code
- 平台：X86-64
- OS：win10 home

## 程序使用结果截图

```
//我用的时候是这个样子，你用，也是这样。 ——成龙
Which one do you want, [Q]ueue or [S]tack ?
Q
Which one do you want, p[U]sh or p[O]p or e[X]it?
O
It is empty
U
C
U
O
U
M
U
P
U
U
U
T
U
E
U
R
O
C
O
O
O
M
O
P
O
U
O
T
O
E
O
R
O
It is empty
```
```
Which one do you want, [Q]ueue or [S]tack ?
S
Which one do you want, p[U]sh or p[O]p or e[X]it?
O
It is empty
U
A
U
B
U
C
U
D
O
D
O
C
O
B
O
A
O
It is empty
```

## 程序使用说明

- 数据存储类型是 字符
- 该程序使用引导型交互
- 进入程序 
    - 输入S，选择使用栈
    - 输入Q，选择使用队列（长度最大值为10）
- 进入输入输出选项
    - 输入U，入栈/队，并输入一个字符作为入栈/队的数据；如果栈/队满，输出it is full。
    - 输入O，出栈/队，输出一个字符；如果栈/队空，输出it is empty
    - 输入X，退出程序

## 编程思路简析

### 栈

- 没有做一个空的头结点，所以说头结点也是一个存数据的普通节点。
- push/pop对头结点的情况都做了特殊处理。
- 没有使用递归

### 队列

- 没有使用数组的空位来表示队满/空，而是使用size变量。

