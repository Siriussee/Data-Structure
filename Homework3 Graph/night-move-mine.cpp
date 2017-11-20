#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int direction[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int chess[8][8];

struct point
{
    int x, y;
    point(int a, int b)
    {
        x = a;
        y = b;
    }
    bool is_good()
    {
        if (0 <= this->x && this->x <= 7 && 0 <= this->y && this->y <= 7 && !chess[x][y])
            return true;
        return false;
    }
    bool is_equal(const point o)
    {
        return (x == o.x && y == o.y);
    }
};

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        //to point (0,0)~(7,7)
        string start, end;
        cin >> start >> end;
        point start_point = point(start[0] - 'a', start[1] - '1');
        const point end_point = point(end[0] - 'a', end[1] - '1');

        int step = 0;
        vector<point> v[64];
        v[0].push_back(start_point);     //add start point
        memset(chess, 0, sizeof(chess)); //init chess
        bool flag = false;
        if (!start_point.is_equal(end_point))
        {
            while (1)
            {
                //for each situation in v (every step)
                for (auto it = v[step].begin(); it != v[step].end(); ++it)
                {
                    //try each direction
                    for (int i = 0 ; i < 8; ++i)
                    {
                        //get current point
                        point curr = *it;
                        //move
                        curr.x += direction[i][0];
                        curr.y += direction[i][1];
                        //if meet need,stop try
                        if (curr.is_equal(end_point))
                        {
                            flag = true;
                            break;
                        }
                        //if dont meet but is good,
                        if (curr.is_good())
                        {
                            //store and wait for next step
                            v[step + 1].push_back(curr);
                            //mark "walked" in chess to avoid repeat try
                            chess[curr.x][curr.y] = 1;
                        }
                    }
                    //if meet need,stop try
                    if (flag)
                        break;
                }
                step++;
                //if meet need,stop try
                if (flag)
                    break;
            }
        }
        cout << "To get from " << start << " to "
             << end << " takes " << step << " knight moves." << endl;
    }
}