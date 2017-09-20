#include <iostream>
using namespace std;
class Queue
{
    char data[10];
    int front = 0;
    int back = 0;
    int size = 0;

  public:
    Queue() {}
    void push(char ch)
    {
        if (size > 9)
        {
            cout << "It is full" << endl;
            return;
        }
        data[back] = ch;
        back++;
        if (back == 10)
            back %= 10;
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "It is empty" << endl;
            return;
        }
        cout << data[front] << endl;
        front++;
        if (front == 10)
            front %= 10;
        size--;
    }
};