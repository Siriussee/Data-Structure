#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Mgraph
{
    //private:
  public:
    int _point;
    int _path;
    bool path[1001][1001];
    bool visited[1001];

  public:
    Mgraph()
    {
        memset(path, false, sizeof(path));
        memset(visited, false, sizeof(visited));
        string str_point, str_path;
        cout << "Number of point: " << flush;
        getline(cin, str_point);
        _point = stoi(str_point);
        cout << "Number of path: " << flush;
        getline(cin, str_path);
        _path = stoi(str_path);
        cout << "Two point in one line to show a path" << endl;
        int a, b;
        for (int i = 0; i < _path; ++i)
        {
            cin >> a >> b;
            if(a<=0 || b <=0 || a >_point || b > _point)
            {
                cout << "invaild number" << endl;
            }
            path[a][b] = path[b][a] = true;
        }
    }
    void bfs()
    {

    }
    void dfs()
    {
    }
    void sr()
    {
    }
};