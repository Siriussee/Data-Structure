//source:http://blog.csdn.net/lohiaufung/article/details/53425780
//并查集

#include <iostream>

using namespace std;

int set[100001];
int findSet(int p);

int main()
{
    int p, q;
    for (int i = 0; i < 100002; i++)
        set[i] = i;

    while (cin >> p >> q)
    {
        if (findSet(p) != findSet(q))
        {
            cout << p << ' ' << q << endl;
            set[findSet(p)] = set[findSet(q)];
        }
    }
    return 0;
}

// 寻找祖先同时让每个节点指向最终祖先
int findSet(int p)
{
    return p == set[p] ? p : (set[p] = findSet(set[p]));
}