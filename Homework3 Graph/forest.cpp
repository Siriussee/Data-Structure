/*
n m
1 0

n m
1 1
a->b
1  1
INV

3 1

1 3

2 2

1 2
2 1
INV

n (EOI)
0 88
*/
#include <iostream>
#include <cstring>
using namespace std;

int width = 0, depth = 0;
int widths[100];

void dfs(int data, int dep)
{

}

int main()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0)
            return 0;
        if (m == 0)
        {
            cout << "0 1" << endl;
            continue;
        }

        int arr[100][2];
        bool walked[100];
        bool is_invaild = false;
        memset(arr, 0, sizeof(arr));
        memset(walked, false, sizeof(walked));
        memset(widths,0,sizeof(widths));
        walked[1] = true;

        //judge vaild
        for (int i = 0; i < m; ++i)
            cin >> arr[i][0] >> arr[i][1];
        for (int i = 0; i < m; ++i)
            if (arr[i][0])
                if (!walked[arr[i][1]])
                    walked[arr[i][1]] = true;
                else
                    is_invaild = true;
        if (is_invaild)
        {
            cout << "INVALID" << endl;
            continue;
        }
        //int depth, width;
        dfs(arr[1][0],depth);
    }
    return 0;
}