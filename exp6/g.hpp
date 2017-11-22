#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Mgraph
{
    //private:
  public:
    int _point;
    int _path;
    bool path[1001][1001];
    bool visited[1001];

    void visit(int p)
    {
        cout << p << " ";
    }

  public:
    Mgraph()
    {
        memset(path, false, sizeof(path));

        string str_point, str_path;
        cout << "Number of point: " << flush;
        getline(cin, str_point);
        _point = stoi(str_point);
        cout << "Number of path: " << flush;
        getline(cin, str_path);
        _path = stoi(str_path);
        cout << "Two point in one line to show a path(begin with 1)" << endl;
        int a, b;
        for (int i = 0; i < _path; ++i)
        {
            cin >> a >> b;
            if (a <= 0 || b <= 0 || a > _point || b > _point)
            {
                cout << "invaild number" << endl;
            }
            path[a][b] = path[b][a] = true;
        }
    }
    void bfs()
    {
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int temp = q.front();
            visit(temp);
            //for every node
            for (int i = 1; i <= _point; ++i)
            {
                //if is connect to this node and never visit
                if (path[temp][i] == true && visited[i] != true)
                { //add to to-visit list
                    visited[i] = true;
                    q.push(i);
                }
            }
            q.pop();
        }
        cout << endl;
    }
    void dfs()
    {
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        dfs_do(1);
        cout << endl;
    }
    void dfs_do(int temp)
    {
        visit(temp);
        //for every node
        for (int i = 1; i <= _point; ++i)
        {
            //if is connect to this node and never visit
            if (path[temp][i] == true && visited[i] != true)
            {
                visited[i] = true; //must before dfs_do(next)
                dfs_do(i);
            }
        }
    }
    void sr()
    {
        int dis[101];
        for (int i = 0; i < 100; ++i)
            dis[i] = 65535;
        dis[1] = 0;

        for (int i = 2; i <= _point; ++i)
            if (path[1][i] == true)
                dis[i] = 1;

        for (int i = 1; i <= _point; ++i)
            for (int j = 1; j <= _point; ++j)
                if (path[i][j] == true)
                    if (dis[i] > dis[j] + path[i][j])
                        dis[i] = dis[j] + path[i][j];

        for (int i = 1; i <= _point; ++i)
            cout << dis[i] << " ";
        cout << endl;
    }
};
class Lgraph
{
  public:
    int _point;
    int _path;
    list<int> neighbors[1001];
    bool visited[1001];
    void visit(int p)
    {
        cout << p << " ";
    }
    Lgraph(Mgraph m)
    {
        _point = m._point;
        _path = m._path;
        for (int i = 1; i <= _point; ++i)
        {
            for (int j = 1; j <= _point; ++j)
            {
                if (m.path[i][j])
                {
                    neighbors[i].push_back(j);
                }
            }
        }
    }
    void bfs()
    {
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int temp = q.front();
            visit(temp);
            //for every node
            for (int i = 1; i <= _point; ++i)
            {
                //if is connect to this node and never visit
                for (auto it = neighbors[temp].begin(); it != neighbors[temp].end(); ++it)
                {
                    if (*it == i && visited[i] != true)
                    { //add to to-visit list
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            q.pop();
        }
        cout << endl;
    }
    void dfs()
    {
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        dfs_do(1);
        cout << endl;
    }
    void dfs_do(int temp)
    {
        visit(temp);
        //for every node
        for (int i = 1; i <= _point; ++i)
        {
            //if is connect to this node and never visit
            for (auto it = neighbors[temp].begin(); it != neighbors[temp].end(); ++it)
                if (*it == i && visited[i] != true)
                {
                    visited[i] = true; //must before dfs_do(next)
                    dfs_do(i);
                }
        }
    }
    void sr()
    {
        int dis[101];
        for (int i = 0; i < 100; ++i)
            dis[i] = 65535;
        dis[1] = 0;

        for (int i = 2; i <= _point; ++i)
            for (auto it = neighbors[1].begin(); it != neighbors[1].end(); ++it)
                if (*it == i)
                    dis[i] = 1;

        for (int i = 1; i <= _point; ++i)
            for (int j = 1; j <= _point; ++j)
                for (auto it = neighbors[i].begin(); it != neighbors[i].end(); ++it)
                    if (*it == j)
                        if (dis[i] > dis[j] + 1)
                            dis[i] = dis[j] + 1;

        for (int i = 1; i <= _point; ++i)
            cout << dis[i] << " ";
        cout << endl;
    }
};