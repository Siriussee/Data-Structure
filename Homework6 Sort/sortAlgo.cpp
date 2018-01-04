#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        vector<int> v;
        int data;
        for (int i = 0; i < n; ++i)
        {
            cin >> data;
            v.push_back(data);
        }
        sort(v.begin(), v.end());
        for (int i = 0;; i += m)
        {
            if (i >= n)
                break;
            cout << v[i];
            if (i < n - m)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}