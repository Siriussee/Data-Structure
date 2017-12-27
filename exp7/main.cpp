#include "address.hpp"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Address a;
    cout << "------ Address App -------" << endl
         << "[s]how" << endl
         << "[f]ind" << endl
         << "[i]nsert" << endl
         << "[d]elete" << endl
         << "[q]uit" << endl
         << "------ Address App -------" << endl;
    string op;
    while (true)
    {
        cout << ">>" << flush;
        getline(cin, op);
        if (op == "s")
            a.show();
        if (op == "f")
            a.find();
        if (op == "i")
            a.insert();
        if (op == "d")
            a.delete_p();
        if (op == "q")
            return 0;
    }
    return 0;
}