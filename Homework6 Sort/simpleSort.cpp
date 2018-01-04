#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int map[101][11];
    int query[11][11];
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> map[i][j];
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i)
            for (int j = 0; j < m; ++j)
                cin >> query[i][j];
        
    }
}