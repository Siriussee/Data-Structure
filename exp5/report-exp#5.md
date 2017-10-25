# 实验报告#4 - 二叉树

## 开发环境

- 编译器：gcc v6.3.0
- 编辑器：VS Code
- 平台：X86-64
- OS：win10 home

## 程序说明

### 运行逻辑

1. 运行程序
1. 输入数据的数量
1. 在一行中输入数据，用空格分开（只接受字母作为输入数据）
1. 程序自动输出建立的树和反向的树
1. 程序结束

### 数据结构

```c++
struct Node
{
    char data;
    Node *left, *right;
    Node(char d)    //构造函数
};
class myTree
{
  private:
    Node *head;
    static int count; 

  public:
    myTree();   //构造函数
    void insert(char d);    //插入
    void print();   //打印树
    void PrintNodeByLevel(Node *root, int level);  //打印树
    void reverseTree(); //反转树（递归实现）
    void reverse(Node* root);   //反转树的辅助函数
    void reverseANode(Node * n); //交换两个节点的函数
};
```

