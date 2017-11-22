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
   // Lgraph l;
    bool isMatrixGraph;
    cout << "Build graph via [M]atrix" << endl
         << "Build graph via [L]ist" << endl
         << "[B]FS" << endl
         << "[D]FS" << endl
         << "[S]hortest route" << endl
         << "[E]xit" << endl;
    string command;
    while (getline(cin, command))
    {
        if (command[0] == 'M')
            isMatrixGraph = true;
        if (command[0] == 'L')
            isMatrixGraph = false;
        if (command[0] == 'B')
            if (isMatrixGraph)
                m.bfs();
            else
        //        l.bfs();
        if (command[0] == 'D')
            if (isMatrixGraph)
                m.dfs();
            else
        //        l.dfs();
        if (command[0] == 'S')
            if (isMatrixGraph)
                m.sr();
            else
        //        l.sr();
        if(command[0] == 'E')
            break;
    }
    return 0;
}