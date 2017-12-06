#include <iostream>
using namespace std;
int map[501][501];
int lowcost[501];
const int inf = 65536;
int main() //shortest road algo
{
    int n;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) //get distance
            for (int j = 0; j < n; j++)
                cin >> map[i][j];

        for (int i = 0; i < n; i++)
            lowcost[i] = map[0][i]; //init lowcost arr

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int mindis = inf;
            int minone;
            for (int j = 0; j < n; j++)
            {
                if (lowcost[j] && mindis > lowcost[j])
                {
                    mindis = lowcost[j];
                    minone = j;
                }
            }
            if (ans < mindis)
                ans = mindis;
            lowcost[minone] = 0;
            for (int j = 0; j < n; j++)
            {
                if (lowcost[j] > map[minone][j])
                    lowcost[j] = map[minone][j];
            }
        }
        cout << ans << endl;
        if (t != 0)
            cout << endl;
    }
    return 0;
}