#include <iostream>
#include <cstdlib>
#include "myTree.hpp"
using namespace std;

static int count = 0;
int main()
{
    myTree tree;
    int n;
    cout << "Enter the number of data(only char will be accepted): " << flush;
    cin >> n;
    char data;
    cout << "Enter the data in one line, saparated in [space]: " << flush;
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