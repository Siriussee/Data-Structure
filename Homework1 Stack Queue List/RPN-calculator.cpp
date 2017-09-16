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
    getline(cin, waste);
    stack<double> s;
    for (int i = 0; i < n; ++i)
    {
        //char ch;
        //while (!isspace(ch = getchar()))        //RE????
        string str;
        getline(cin, str);
        for (int i = 0; i < str.size(); ++i)
        {
            if (isalpha(str[i]))
                s.push(str[i] + 1 - 'a');
            else
            {
                double b = s.top(); //mind the order of a&b
                s.pop();
                double a = s.top();
                s.pop();
                if (str[i] == '+')
                    s.push(a + b);
                if (str[i] == '-')
                    s.push(a - b);
                if (str[i] == '*')
                    s.push(a * b);
                if (str[i] == '/')
                    s.push(a / b);
            }
        }
        cout << setprecision(2) << fixed << s.top() << endl;
        s.pop();
    }
    return 0;
}