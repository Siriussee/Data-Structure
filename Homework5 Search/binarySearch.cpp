#include <iostream>
using namespace std;
int binSearch(const int s[], const int size, const int target);
int main(int argc, const char *argv[])
{
    // insert code here...
    int s[8] = {0,1,1,3,3,3,6,6};
    cout << binSearch(s, 8, 3) << endl;
    cout << binSearch(s, 8, 4) << endl;
    cin.get();
    return 0;
}

// `0 1 ``1 ``3 3 ```*3 ```6 *6

int binSearch(const int s[], const int size, const int target)
{
    int lhs = 0, rhs = size - 1, mid;
    while (lhs < rhs)
    {
        mid = lhs + (rhs - lhs) / 2;
        if (s[mid] > target)
        {
            rhs = mid - 1;
            continue;
        }
        if (s[mid] == target && s[mid + 1] != target) //target meet && the next doesnot meet
            return mid;
        lhs = mid + 1;
    }
    if (s[rhs] != target)
        return -1;
    return rhs;
}