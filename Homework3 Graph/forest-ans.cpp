#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
#define MAX 105

vector<int> vec[MAX];
int widths[MAX];
bool visit[MAX], isforest, into[MAX];
int n, m, depth, width;

void dfs(int i,int d)
{
    if(visit[i]==1)
    {
        isforest = 0;
        return;
    }
    visit[i]=1;
    if (d>depth)
		depth=d;
    widths[d]++;
    if (widths[d] > width)  
		width = widths[d];
    for (int j=0; j< vec[i].size(); j++)
        dfs(vec[i][j], d+1);
}

int main()
{
    int i,temp1,temp2;
    while(scanf("%d%d", &n, &m)!=EOF&&n!=0)
    {
        memset(into,0,sizeof(into));
        memset(visit,0,sizeof(visit));
        memset(widths,0,sizeof(widths));
        memset(vec,0,sizeof(vec));
        depth=0,width=0;
        isforest=1;
        while(m--)
        {
            scanf("%d%d", &temp1, &temp2);
            vec[temp1].push_back(temp2);
            if (into[temp2]==1||temp1==temp2)
                isforest=0;
            else  into[temp2]=1;
        }
        if (isforest==0)
        {
            printf("INVALID\n");
            continue;
        }
        for (i=1;i<=n;i++)
            if(into[i]==0)
                dfs(i,0);
        for (i=1;i<=n;i++)
        {
            if(visit[i]==0)
            {
                isforest=0;
                break;
            }
        }
        if (isforest==0)
            printf("INVALID\n");
        else
            printf("%d %d\n", depth, width);
    }
    return 0;
}