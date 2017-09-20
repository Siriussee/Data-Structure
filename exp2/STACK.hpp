#include <iostream>

using namespace std;
struct Node
{
    char data;
    Node *next = NULL;
};

class Stack
{
    Node *head;
    int size;

  public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    ~Stack()
    {
        while (head != NULL)
            pop();
        size = 0;
    }
    void push(char ch)
    {
        Node *new_node = new Node;
        new_node->data = ch;
        if (head == NULL)
        {
            head = new_node;
            size++;
            return;
        }
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        ++size;
    }
    void pop()
    {
        Node *current = head;
        if (current == NULL)
        {
            cout << "It is empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            cout << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        Node *current_father;
        while (current->next != NULL)
        {
            current_father = current;
            current = current->next;
        }
        cout << current->data << endl;
        delete current;
        current_father->next = NULL;
        --size;
    }
};