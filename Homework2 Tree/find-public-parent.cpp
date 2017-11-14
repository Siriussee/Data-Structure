//do not use iostream    //std::ios::sync_with_stdio(false);   //a replacement
//do not use STL
//or you will meet time limited error
//use loop for even faster solution

#include <cstdio>

using namespace std;

int find_father(int x, int y)
{
    if (x == y)
        return x;
    if (x > y)
        return find_father(x / 2, y);
    return find_father(x, y / 2);
}
int main()
{

    int T;
    //cin >> T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        int a, b;
        //cin >> a >> b;
        scanf("%d%d", &a, &b);
        printf("%d\n",find_father(a,b));
    }
    return 0;
}
