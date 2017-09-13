#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
//genarate some ramdon int from 0-100
//will be saved in ramdon.txt
int main()
{
    srand(666);
    int number;
    ofstream os("random.txt", ios::out);

    cout << "How many random int do you want?" << endl;
    cin >> number;
    
    for (int i = 0; i < number; ++i)
    {
        os << rand() % 100 << " ";
        cout << rand() % 100 << " ";
    }
    os << endl;
    cout << endl;
    return 0;
}