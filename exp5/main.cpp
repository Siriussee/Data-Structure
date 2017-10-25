#include <iostream>
#include <cstdlib>
#include <cctype>
#include "myTree.hpp"
using namespace std;

static int count = 0;
int main()
{
    myTree tree;
    int n;
    cout << "Enter the number of data: " << flush;
    cin >> n; n = (int)n;
    if(0 > n || n > 30)
    {
        cout << "Invaild input" << endl;
        system("pause");
        return 0;
    }
    char data;
    cout << "Enter the data in one line(only char will be accepted), saparated in [space]: " << endl;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> data;
        tree.insert(data);
    }
    cout << "This is the original tree" << endl;
    tree.print();
    cout << endl;
    cout << "This is the tree after reverse" << endl;
    tree.reverseTree();
    tree.print();
    system("pause");
    return 0;
}