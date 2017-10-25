#include <iostream>
#include <cstdlib>
#include "myTree.hpp"
using namespace std;

static int count = 0;
int main()
{
    myTree tree;
    int n;
    cin >> n;
    char data;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> data;
        tree.insert(data);
    }
    tree.print();
    cout << endl;
    tree.reverseTree();
    tree.print();
    system("pause");
    return 0;
}