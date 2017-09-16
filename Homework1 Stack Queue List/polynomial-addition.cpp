#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        map<int, int> poly;

        int poly_num;
        cin >> poly_num;
        while (poly_num--)
        {
            if (poly_num < 0)
                break;
            int coefficient, index;
            cin >> coefficient >> index;
            poly[index] = coefficient;
        }
        int add_poly_num;
        cin >> add_poly_num;
        while (add_poly_num--)
        {
            if (add_poly_num < 0)
                break;
            int coefficient, index;
            cin >> coefficient >> index;
            if (poly.count(index))
                poly[index] += coefficient;
            else
                poly[index] = coefficient;
        }
        int count = 0;
        for (auto it = poly.begin(); it != poly.end(); ++it)
        {
            if (it->second != 0)
                count++;
        }
        cout << count << endl;
        for (auto rit = poly.rbegin(); rit != poly.rend(); ++rit) //reverse_iterator
        {
            if (rit->second != 0)
                cout << rit->second << " " << rit->first << endl;
        }
    }
    return 0;
}