#include <iostream>

struct ListNode
{
    int data;
    ListNode *next;
};

class List
{
  public:
    List()
    {
        head = new ListNode;
        head->next = NULL;
    }

    ~List()
    {
        ListNode *curNode;
        while (head->next)
        {
            curNode = head->next;
            head->next = curNode->next;
            delete curNode;
        }
        delete head;
    }
    //在链表第pos(pos>0)个结点之前插入新结点，新结点的值为toadd
    //链表实际结点从1开始计数。
    //调用时需保证pos小等于链表实际结点数
    void insert(int toadd, int pos)
    {
        ListNode *new_node = new ListNode;
        new_node->data = toadd;
        int count = pos - 1;
        ListNode *current = head;
        while (count--)
        {
            current = current->next;
        }
        ListNode *current_next = current->next;
        current->next = new_node;
        new_node->next = current_next;
    }

    //删除链表的第pos(pos>0)个结点
    //链表实际结点从1开始计数。
    //调用时需保证pos小等于链表实际结点数
    void remove(int pos)
    {
        int count = pos - 1;
        ListNode *current = head;
        while (count--)
        {
            current = current->next;
        }
        ListNode *current_next = current->next;

        current->next = current_next->next;
        delete current_next;
    }

    // Data field
    ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
};

int main()
{
    List l;
    l.insert(10, 1);
    l.insert(10, 2);
    l.remove(1);
}
