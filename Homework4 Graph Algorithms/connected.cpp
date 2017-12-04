//dead code

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <list>
using namespace std;

//bool arr[100001][100001];
list<int> neighbors[100001];
bool visited[100001];
bool isConnect(int m, int n);

int main()
{
    //memset(arr, false, sizeof(arr));
    int m, n;
    while (cin >> m >> n)
        if (!isConnect(m, n))
            cout << m << " " << n << endl;
    return 0;
}

bool isConnect(int m, int n)
{
    memset(visited, false, sizeof(visited));
    visited[m] = true;
    queue<int> q;
    bool flag = false;
    q.push(m);
    while (!q.empty())
    {
        int temp = q.front();
        //if find connected,stop BFS
        if (temp == n)
        {
            flag = true;
            break;
        }
        //for every node
        for (int i = 1; i <= 100000; ++i)
        {
            //if is connect to this node and never visit
            for (auto it = neighbors[temp].begin(); it != neighbors[temp].end(); ++it)
            {
                if (*it == i && visited[i] != true)
                { //add to to-visit list
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    if (flag)
        return true;
    //vec[m].push_back(n);
    //vec[n].push_back(m);
    //arr[m][n] = arr[n][m] = true;
    neighbors[m].push_back(n);
    neighbors[n].push_back(m);
    return false;
}