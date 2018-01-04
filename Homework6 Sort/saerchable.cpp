#include <iostream>
using namespace std;

int main()
{
    int length;
    while (cin >> length)
    {
        int data[100];
        int count = 0;
        for (int i = 0; i < length; i++)
            cin >> data[i];
        for (int i = 0; i < length; i++)
        {
            bool isSmaller = true, isLarger = true;
            for (int j = 0; j < i; ++j)
            {
                if (data[j] > data[i])
                {
                    isSmaller = false;
                    break;
                }
            }
            for (int j = i + 1; j < length; ++j)
            {
                if (data[j] < data[i])
                {
                    isLarger = false;
                    break;
                }
            }
            if (isSmaller && isLarger)
                count++;
        }
        cout << count << endl;
    }

    return 0;
}