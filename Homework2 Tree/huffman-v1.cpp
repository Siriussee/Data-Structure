#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[27];
    for (int i = 0; i < 27; ++i)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        char ch;
        cin >> ch;
        arr[ch - 'A']++;
    }
    return 0;
}