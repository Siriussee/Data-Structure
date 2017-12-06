#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int buffer[202][202];   //one line may contain 2 dist, at most 100 lines
int len[202];
bool visited[202];

int dijkstra(int b, int e, int n)
{
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
        len[i] = 65536;
    len[b] = 0;
    for (int i = 0; i < n; i++)
    {
        int min = 65536;
        int v = b;
        for (int j = 0; j < n; j++)
            if (!visited[j] && len[j] < min)
            {
                min = len[j];
                v = j;
            }
        visited[v] = true;
        for (int j = 0; j < n; j++)
            if (!visited[j] && len[v] + buffer[v][j] < len[j])
                len[j] = len[v] + buffer[v][j];
    }
    if (visited[e])
        return len[e];
    else
        return -1;
}

int main()
{
    int c, n, l;
    string b, e;
    cin >> c;
    while (c--)
    {
        cin >> n;
        map<string, int> sysu;
        int num = 0;
        for (int i = 0; i < 202; i++)
            for (int j = 0; j < 202; j++)
                buffer[i][j] = (i == j ? 0 : 65536);
        for (int i = 0; i < n; i++)
        {
            cin >> b >> e >> l;
            if (!sysu.count(b))     //mark every target by a unique ID
                sysu[b] = num++;
            if (!sysu.count(e))
                sysu[e] = num++;
            buffer[sysu[b]][sysu[e]] = buffer[sysu[e]][sysu[b]] = l;
        }
        cin >> b >> e;
        if (b == e)
            cout << 0 << endl;
        else if (!sysu.count(b) || !sysu.count(e))
            cout << -1 << endl;
        else
            cout << dijkstra(sysu[b], sysu[e], num) << endl;
    }
    return 0;
}