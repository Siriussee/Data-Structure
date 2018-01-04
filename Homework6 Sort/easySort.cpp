#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int data;
        vector<int> v;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> data;
            v.push_back(data);
        }
        sort(v.begin(), v.end());
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            cout << *it << endl;
        }
    }
    return 0;
}