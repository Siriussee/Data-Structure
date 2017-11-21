#include <iostream>

using namespace std;

int edge_type[101][101];
/*
1. 树枝，是深度优先森林Gπ中的边，如果结点v是在探寻边(u,v)时第一次被发现，那么边(u,v)就是一个树枝。 
2. 反向边，是深度优先树中连结结点u到它的祖先v的那些边，环也被认为是反向边。 
3. 正向边，是指深度优先树中连接顶点u到它的后裔的非树枝的边。 
4. 交叉边，是指所有其他类型的边，它们可以连结同一棵深度优先树中的两个结点，
*/
int point_num, edge_num;

int main()
{
    cin >> point_num >> edge_num;
    memset(edge, 0, sizeof(edge));
    for (int i = 0; i < edge_num; ++i)
    {
        int u, v;
        cin >> u >> v;
        edge[u][v] = 1;
    }

    comfirm_type();

    int ask_number;
    cin >> ask_number;
    for (int i = 0; i < ask_number; ++i)
    {
        int u, v;
        cin >> u >> v;
    }
}