#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string waste;
    getline(cin,waste);
    for (int i = 0; i < n; ++i)
    {
        char ch;
        stack<int> s;
        while ((ch = getchar()) != '\n')
        {
            if (isalnum(ch))
            {
                int real = ch + 1 - 'a';
                s.push(real);
            }
            if (ch == '+')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(a + b);
            }
            if (ch == '-')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(a - b);
            }
            if (ch == '*')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(a * b);
            }
            if (ch == '/')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(a / b);
            }
        }
        double ans = s.top();
        cout << fixed<< setprecision(2) << ans << endl;
    }
    return 0;
}