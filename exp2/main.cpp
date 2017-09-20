#include "STACK.hpp"
#include "QUEUE.hpp"
#include <iostream>
using namespace std;
int main()
{
    cout << "Which one do you want, [Q]ueue or [S]tack ?" << endl;
    char option;

    cin.get(option);
    if (option == 'Q')
    {
        Queue q;
        cout << "Which one do you want, p[U]sh or p[O]p or e[X]it?" << endl;
        char data;
        while (cin.get(option))
        {
            if (option == 'U')
            {
                cin >> data;
                q.push(data);
                //cout << "push" << endl;
            }
            if (option == 'O')
            {
                q.pop();
                //cout << "pop" << endl;
            }
            if (option == 'X')
                return 0;
        }
    }
    else if (option == 'S')
    {
        Stack s;
        cout << "Which one do you want, p[U]sh or p[O]p or e[X]it?" << endl;
        char data;
        while (cin.get(option))
        {
            if (option == 'U')
            {
                cin >> data;
                s.push(data);
            }
            if (option == 'O')
            {
                s.pop();
                //cout << "pop" << endl;
            }
            if (option == 'X')
                return 0;
        }
    }
    return 0;
}