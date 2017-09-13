#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string waste;
    getline(cin, waste);
    for (int i = 0; i < N; ++i)
    {
        char ch;
        bool flag = true;
        stack<char> s;
        while ((ch = getchar()) != '\n')
        {
            if (ch == '{' || ch == '[' || ch == '(')
                s.push(ch);
            if (ch == '}')
            {
                if (s.empty() || s.top() != '{')
                {
                    flag = false;
                    getline(cin, waste);
                    break;
                }
                s.pop();
            }
            if (ch == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    flag = false;
                    getline(cin, waste);
                    break;
                }
                s.pop();
            }
            if (ch == ')')
            {
                if (s.empty() || s.top() != '(') //front lack "{}}" or cannot match "(]"
                {
                    flag = false;
                    getline(cin, waste);
                    break;
                }
                s.pop();
            }
                }
        if (!s.empty()) //too many "((()"
            flag = false;
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}