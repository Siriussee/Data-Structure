#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include "g.hpp"

using namespace std;

int main()
{
    cout << "enter data" << endl;
    Mgraph m;
    Lgraph l(m);
    bool isMatrixGraph;
    cout << "[M]atrix graph" << endl
         << "[L]ist graph" << endl
         << "[B]FS" << endl
         << "[D]FS" << endl
         << "[S]hortest route" << endl
         << "[E]xit" << endl;
    string command;
    while (getline(cin, command))
    {
        if (command == "M")
        {
            isMatrixGraph = true;
            cout << "Initializing a Matrix Graph..." << endl;
        }
        if (command == "L")
        {
            isMatrixGraph = false;
            cout << "Initializing a List Graph..." << endl;
        }
        if (command == "B")
            cout << "BFS:" << endl;
        {
            if (isMatrixGraph)
                m.bfs();
            else
                l.bfs();
        }
        if (command == "D")
        {
            cout << "BFS:" << endl;
            if (isMatrixGraph)
                m.dfs();

            //        l.dfs();
        }
        if (command == "S")
        {
            cout << "Shortest route from 1 to other:" << endl;
            if (isMatrixGraph)
                m.sr();

            //        l.sr();
        }
        if (command == "E")
            break;
    }
    return 0;
}