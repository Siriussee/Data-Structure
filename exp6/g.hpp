#include <iostream>
#include <cstring>
#include <string>
#include <vector>

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

struct ArcNode
{
    int adjvex;    //该弧所指向的顶点的位置
    ArcNode *next; //指向下一条弧的指针
};

struct VNode
{
    char vertex;       //顶点信息
    ArcNode *firstarc; //指向第一条依附该顶点的弧的指针
};

class Lgraph
{
  public:
    int _point;
    int _path;
    bool visited[1001];
    VNode adjList[20];

    void visit(int p)
    {
        cout << p << " ";
    }
    Lgraph(Mgraph m)
    {
        _point = m._point;
        _path = m._path;
        for (int i = 1; i <= _point; ++i)
            for (int j = i; j <= _point; ++j)
                if (m.path[i][j] == true)
                {
                    ArcNode* temp = new ArcNode;
                    temp->adjvex = j;
                    temp->next = adjList[i].firstarc;
                    adjList[j].firstarc = temp;
                }
    }
    void bfs()
    {
        memset(visited, false, sizeof(visited));
        queue<int> q;

        for (int i = 0; i < _point; i++)
        {
            if (!visited[i]) //如果没有访问过
            {
                visited[i] = true;
                q.push(i); //访问过的入队列
                cout << adjList[i].vertex << " ";

                while (!q.empty()) //队列不为空时
                {
                    int x = q.front();
                    q.pop(); //先取出队首第一个元素，然后将第一个元素删除
                    ArcNode *p = adjList[x].firstarc;
                    while (p) //访问未被访问过的邻接顶点
                    {
                        if (!visited[p->adjvex])
                        {
                            visited[p->adjvex] = true;
                            cout << adjList[p->adjvex].vertex << " ";
                            q.push(p->adjvex);
                        }

                        p = p->next;
                    }
                }
            }
        }
    }
    void dfs()
    {
    }
    void sr()
    {
    }
};

/*
/*
struct Arc
{
    int adjvex;
    Arc *next;
    Arc(int x) { adjvex = k; }
};

struct Node
{
    int data;
    Node *next;
    Node(int d)(data = d;)
};

class Lgraph
{
  public:
    int _point;
    int _path;

    Node *head[1001];

    //bool path[1001][1001];
    bool visited[1001];

    void visit(int p)
    {
        cout << p << " ";
    }

    Lgraph(Mgraph m)
    {
        memset(head, NULL, sizeof(head));
        _point = m._point;
        _path = m._path;
        /*
        Arc *temp;
        for (int i = 1; i <= _point; ++i)
            for (int j = 1; j <= _point; ++j)
            {
                if (m.path[i][j] == true)
                {
                    temp = new Arc(j);
                    temp->next = head[i].first;
                    head[i].first = temp;
                }
            }

        for (int i = 1; i <= _point; ++i)
        {
            Node *head = new Node(i);
            Node *curr = head;
            for (int j = 1; j <= _point; ++j)
            {
                if (m.path[i][j] == true)
                {
                    Node *newNode = new Node(j);
                    cruu->next = newNode;
                    curr = newNode;
                }
            }
        }
    }

    void dfs()
    {
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        dfs_do(head[0]);
        cout << endl;
    }
    void dfs_do(Node *temp)
    {
        visit(temp->data);
        //for every node
        for (int i = 1; i <= _point; ++i)
        {
            //if is connect to this node and never visit
            if (temp->next != NULL && visited[temp->next->data] == false)
            {
                visited[temp->next->data] = true; //must before dfs_do(next)
                dfs_do(temp->next);
            }
        }
    };
    */