#include <iostream>
#include <string>
#include "myList.hpp"
using namespace std;

int main ()
{
    array_list al;
    link_list ll;
    cout << "List based on [a]rray or based on [l]inklist?" << endl;
    string op;
    getline(cin,op);
    cout << "- [i]nsert "<< endl
    <<  "- [e]rase "<< endl
    << "- [q]uit" << endl;
    if(op == "a")
    while(1)
    {
        string op2;
        
        cin.clear();cin.sync();
        getline(cin, op2);
        if(op2 == "i")
        {
            cout << "- data: " << flush;
            string data;
            getline(cin,data);
            cout << "- position: " << flush;
            int position;
            cin >> position; 
            al.insert(data[0],position);
        }
        if(op2 == "e")
        {
            cout << "- position: " << flush;
            int position;
            cin >> position; 
            al.erase(position);
        }
        if(op2 == "q")
            break;
        al.print_all();
    }
    if(op == "l")
    while(1)
    {
        string op2;
        cin.clear();cin.sync();
        getline(cin, op2);
        if(op2 == "i")
        {
            cout << "data: " << flush;
            string data;
            getline(cin,data);
            cout << "position: " << flush;
            int position;
            cin >> position; 
            ll.insert(data[0],position);
        }
        if(op2 == "e")
        {
            cout << "position: " << flush;
            int position;
            cin >> position; 
            ll.erase(position);
        }
        if(op2 == "q")
            break;
        ll.print_all();
    }
    return 0;

}