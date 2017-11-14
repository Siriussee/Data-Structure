/*
    Q：给定前序遍历和后序遍历的顺序，
    要求出总共有多少棵不同形态的二叉树满足这样的遍历顺序。
    A：当某节点只有1个子节点时，前序和后序遍历时无法判断左右的。
    问题化简为寻找只有一个子节点的节点数。
    这种节点在前序和后序序列中具有一个特征：A_BC_D _CB_DA
    存在一对顺序相反的子字符串。
*/

#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string str1, str2;
    cin >> str1 >> str2;
    int ans = 1;
    for (int i = 1; i < str1.size(); ++i)
        for (int j = str2.size() - 2; j >= 0; --j)
            if (str1[i] == str2[j] && str1[i-1] == str2[j+1])
            {
                ans *= 2;
                break;
            }

    //cout << ans << endl;
    cout << ans;
    return 0;
}