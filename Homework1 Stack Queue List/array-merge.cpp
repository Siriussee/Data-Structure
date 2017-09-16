#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; ++i)
    {
        int val;
        cin >> val;
        arr[i] = val;
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = i; j < 10; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}