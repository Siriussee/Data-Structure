#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    int i, j;
    queue<int> q;
    int count, set;
    bool visited[1001];
    bool path[1001][1001];

    memset(visited, false, sizeof(visited));
    memset(path, false, sizeof(path));
    cin >> n >> m;
    while (m--)
    {
        cin >> i >> j;
        path[i][j] = true;
        path[j][i] = true;
    }

    count = 0;
    set = 0;
    while (count != n)
    {
        for (i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
                count++;
                set++;
                break;
            }
        }

        while (!q.empty())
        {
            i = q.front();
            for (j = 1; j <= n; j++)
            {
                if (path[i][j] && !visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                    count++;
                }
            }
            q.pop();
        }
    }
    cout << set << endl;

    return 0;
}