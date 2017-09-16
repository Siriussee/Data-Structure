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
    //�������pos(pos>0)�����֮ǰ�����½�㣬�½���ֵΪtoadd
    //����ʵ�ʽ���1��ʼ������
    //����ʱ�豣֤posС��������ʵ�ʽ����
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

    //ɾ������ĵ�pos(pos>0)�����
    //����ʵ�ʽ���1��ʼ������
    //����ʱ�豣֤posС��������ʵ�ʽ����
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
    ListNode *head; //headָ������ͷ��㣬head-nextָ���һ��ʵ�ʽ��
};

int main()
{
    List l;
    l.insert(10, 1);
    l.insert(10, 2);
    l.remove(1);
}
