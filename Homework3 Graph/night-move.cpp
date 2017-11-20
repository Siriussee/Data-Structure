#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct node
{
    int x;
    int y;
};

//骑士走日
int move[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int used[9][9];
int startx, starty, endx, endy;

bool safe(int x, int y)
{
    if (x > 0 && y > 0 && x <= 8 && y <= 8 && used[x][y] == 0)
        return true;
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char s, e;
        vector<node> v[64];

        cin >> s >> startx;
        starty = s - 'a' + 1;
        cin >> e >> endx;
        endy = e - 'a' + 1;

        node no;
        no.x = startx;
        no.y = starty;
        int k = 0;
        int flag = 0;

        v[0].push_back(no);
        //用memset初始化
        memset(used, 0, sizeof(used));
        used[startx][starty] = 1;

        if (startx != endx || starty != endy)
        {
            //vector实现BFS
            while (1)
            {
                vector<node>::iterator it;
                for (it = v[k].begin(); it != v[k].end(); it++)
                {
                    node f = *it;
                    for (int i = 0; i < 8; i++)
                    {
                        node tmp;
                        tmp.x = f.x + move[i][0];
                        tmp.y = f.y + move[i][1];
                        if (tmp.x == endx && tmp.y == endy)
                        {
                            flag = 1;
                            break;
                        }
                        if (safe(tmp.x, tmp.y))
                        {
                            v[k + 1].push_back(tmp);
                            used[tmp.x][tmp.y] = 1;
                        }
                    }
                    if (flag == 1)
                    {
                        break;
                    }
                }
                k++;
                if (flag == 1)
                {
                    break;
                }
            }
            cout << "To get from " << s << startx << " to " << e << endx << " takes " << k << " knight moves." << endl;
        }
        else
        {
            cout << "To get from " << s << startx << " to " << e << endx << " takes "
                 << "0"
                 << " knight moves." << endl;
        }
    }
    return 0;
}