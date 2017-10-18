#include <iostream>
using namespace std;

class array_list
{
    char data[100];
    int size;

  public:
    array_list()
    {
        size = 0;
    }
    bool insert(char ch, int pos)
    {
        if (pos < 0 || pos > size)
        {
            cout << "invaild position" << endl;
            return false;
        }
        for (int i = size - 1; i >= pos; --i)
        {
            data[i + 1] = data[i];
        }
        data[pos] = ch;
        size++;
        return true;
    }
    bool erase(int pos)
    {
        if (pos < 0 || pos > size - 1)
        {
            cout << "invaild position" << endl;
            return false;
        }
        for (int i = pos; i < size; ++i)
        {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
    void print_all()
    {
        cout << "- [current data field]";
        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

struct Node
{
    char data;
    Node *next;
    Node(char d)
    {
        data = d;
        next = NULL;
    }
};

class link_list
{
    int size;
    Node *head;

  public:
    link_list()
    {
        size = 0;
        head = NULL;
    }
    bool insert(char data, int pos)
    {
        if (pos < 0 || pos > size)
        {
            cout << "invaild position" << endl;
            return false;
        }
        Node* new_node;
        new_node = new Node(data);
        if (pos == 0 && size == 0)
        {
            head = new_node;
            size++;
            return true;
        }
        if (pos == 0 && size != 0)
        {
            Node* curr = new_node;
            curr->next = head;
            head = curr;
            size++;
            return true;
        }
        Node* curr = head;
        Node* before = head;
        while (pos--)
        {
            before = curr;
            curr = curr->next;
        }
        before->next = new_node;
        new_node->next = curr;
        size++;
        return true;
    }

    bool erase(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "invaild position" << endl;
            return false;
        }
        if (pos == 0)
        {
            head = head->next;
            size--;
            return true;
        }
        Node* curr = head;
        Node* before = head;
        while (pos--)
        {
            before = curr;
            curr = curr->next;
        }
        before->next = curr->next;
        delete curr;
        size--;
        return true;
    }
    void print_all()
    {
        cout << "- [current data field]";
        Node* curr = head;
       while (curr != NULL)
        {
            cout << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }
};