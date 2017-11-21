#include <iostream>
#include <cstring>
#include <queue>
#include<cstdlib>
using namespace std;

int n, m;
bool path[1001][1001];
bool visit[1001];
int main()
{
    cin >> n >> m;
    memset(path, false, sizeof(path));
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < m; ++i)
    {
        int v,y;
        cin >> v >> y;
        path[v][y] = path[y][v] = true;
    }
    //int i,j;
    int dist = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
       int count = q.size();
        dist++;
        while (count--)
        {
            int temp = q.front();
            for (int j = 1; j <= n; ++j)
            {
                if (path[temp][j] && !visit[j])
                {
                    q.push(j);
                    visit[temp] = dist;
                }
            }
            q.pop();
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << visit[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}