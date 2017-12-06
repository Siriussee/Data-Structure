//建立一个同步的跟踪各个节点入度数的数组，
//随着排序的进行不断更新，
//然后添加新的入度为0的节点到一个set里面，
//每次输出最前的，也就是最小的那个节点，以此来保证字典序最小。

#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int T;
    int n, m;
    int i, j;
    set<int> s;
    int indegree[100001] = {};
    vector<int> v[100001];

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        while (m--) //统计入度
        {
            scanf("%d%d", &i, &j);
            v[i].push_back(j);
            indegree[j]++;
        }

        for (i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)   //入度为0（可以立刻开始），加入set
                s.insert(i);
        }
        while (!s.empty())
        {
            i = *s.begin();         //弹出字典序最小的任务
            printf("%d ", i);
            s.erase(s.begin());
            while (!v[i].empty())   //检查还有没有未完成的任务
            {
                if (--indegree[v[i].back()] == 0)   //该任务可以开始
                    s.insert(v[i].back());          
                v[i].pop_back();
            }
        }
        printf("\n");
    }

    return 0;
}