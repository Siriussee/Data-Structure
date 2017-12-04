#include <iostream>

using namespace std;

int arr[501][501];
int dist[501];
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < t; ++i)
    {
        int city;
        cin >> city;
        for (int i = 0; i < city; ++i)
        {
            for (int j = 0; j < city; ++j)
            {
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < city; ++i) 
        {
            dist[i] = sr(i);
        }
    }
}

void sr(int i)
{
    int dis[101];
    for (int i = 0; i < 100; ++i)
        dis[i] = 65535;
    dis[1] = 0;

    for (int i = 2; i <= _point; ++i)
        for (auto it = neighbors[1].begin(); it != neighbors[1].end(); ++it)
            if (*it == i)
                dis[i] = 1;//not = 1 again

    for (int i = 1; i <= _point; ++i)
        for (int j = 1; j <= _point; ++j)
            for (auto it = neighbors[i].begin(); it != neighbors[i].end(); ++it)
                if (*it == j)
                    if (dis[i] > dis[j] + 1)//not + 1 again
                        dis[i] = dis[j] + 1;//not + 1 again
    int sum = 0;
    for (int i = 1; i <= _point; ++i)
        sum += dis[i];
    return sum;
}