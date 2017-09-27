# 实验#3 bag 实验报告

## 开发环境

- 编译器：gcc v6.3.0
- 编辑器：VS Code
- 平台：X86-64
- OS：win10 home

## 程序使用结果截图

实验样例1

```c++
//我用的时候是这个样子，你用，也是这样。 ——成龙
What is the capacity of the bag?
10
how many item do you have?
6
please enter the weight of each item, saparated by space
1 8 4 3 5 2
the possible solutions are listed:
4 3 2 1
5 4 1
5 3 2
8 2
```

实验样例2

```c++
What is the capacity of the bag?
20
how many item do you have?
8
please enter the weight of each item, saparated by space
2 10 7 16 5 4 9 1
the possible solutions are listed:
10 7 2 1
9 5 4 2
9 7 4
16 4
```

## 程序使用说明

- 引导型交互，按照提示输入数据即可完成操作。
- 第一项要求输入背包的容量，第二项要求输入物体的数量，第三项要求输入各物体的体积，以空格分开
- 输出：程序会以大小降序输出所有可能的组合，每行一个，没有则为空

## 编程思路简析

- 使用 vector 存储体积数据
- 因为不想用递归，所以选用了循环的做法
- 利用两重循环对体积数组进行遍历
- 利用栈 s 作为背包进行体积的 push&pop ，
- **利用栈 c_s 作为储存【体积下标】的【背包】**，从而在背包装满/过满后，实现精准地**取背包中倒数第二个物体的下一个**的操作
- 利用 s & c_s 的同时 push&pop ，模拟 pair 的行为，实现 index 与 weight 的对应关系（灵感来自打印机）
- 创建一个栈 s 的拷贝，栈 s_copy 作为输出
- 最后加了`system("pause")` 会导致非windows用户报错，可以注释掉再在类unix系统上使用