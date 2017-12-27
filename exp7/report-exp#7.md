# 实验报告#7 - 二叉树


## 开发环境

- 编译器：gcc v6.3.0
- 编辑器：VS Code
- 平台：X86-64
- OS：win10 home

## 程序说明

### 运行逻辑

运行程序，弹出字符选单

- 输入s，查看全部学生
- 输入f，按姓名查找学生
- 输入i，往花名册增加学生
- 输入d，删除学生
- 输入q，退出程序

### 数据结构

```c++
struct node // 储存学生信息的节点
{
    string name, sex, id, phone;    //学生信息
    node *next;                     //指向下一个节点的指针
    node();                         //默认构造器
    node(string n, string s, string i, string p);     //构造器

};
class Address
{
    node *hashTable[50];            //花名册的哈希表
    void insert_h(string n, string s, string i, string p);  //插入函数的辅助函数
    bool find_h(string name);       //查找函数的辅助函数

  public:
    Address();                      //初始化
    void show();                    //查看全部学生
    void find();                    //按姓名查找学生
    void insert();                  //往花名册增加学生，使用拉链法处理冲突
    void delete_p();                //删除学生
};
```

### 算法设计

哈希函数

我使用姓名的全部ASACII码之和模50作为哈希函数。

```c++
int sum = 0;
for (int i = 0; i < n.length(); ++i)
   sum += (int)n[i];                //求ASCII码和
sum %= 50;                          //模50
handle(hashTable[sum]);             //……处理……
```

初始化/构造器

我在初始化时就利用 `insert()` 函数插入了一些学生。

```c++
for (int i = 0; i < 50; ++i)
      hashTable[i] = NULL;          //清空哈希表
for (int i = 0; i < 20; ++i)
      insert_h(name,sex,id,phone);  //插入一些数据
```

插入

```c++
void insert_h(string n, string s, string i, string p)
{
      node *new_node = new node(n, s, i, p);
      int sum = hash(n);            //取得哈希值
      if (hashTable[sum] == NULL)   //如果当前哈希值没有冲突，放入此处
            hashTable[sum] = new_node;
      else                          //产生冲突，
      {
      node *curr = hashTable[sum];
      while (curr->next != NULL)    //沿单向链表向下查找，
            curr = curr->next;
      curr->next = new_node;        //加入末尾
      }
}
```


## 运行结果

```c++

```