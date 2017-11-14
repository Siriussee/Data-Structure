/*
                1,1
            2,1     1,2
      3,1     2,3     3,2     1,3
   4,1-3,4| 5,3-2,5| 5,2-3,5| 4,3-1,4 

*/

#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int a, b;
        cin >> a >> b;
        int left = 0, right = 0;
        while (a != 1 || b != 1)
        {
            if (a == b)
                break;
            if (a > b)
            {
                a = a - b;
                left++;
            }
            if (b > a)
            {
                b = b - a;
                right++;
            }
        }
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << left << " " << right << endl;
    }
    return 0;
}