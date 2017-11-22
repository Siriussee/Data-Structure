#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Node
{
    int ch;
    int weight;
    string code;
    Node *left, *right;
    Node(int c, int n)
    {
        ch = c;
        weight = n;
        left = right = NULL;
    }
    Node(Node *a, Node *b)
    {
        ch = -1;
        weight = a->weight + b->weight;
        left = a;
        right = b;
    }
};

//from big to small
bool cmp(Node *a, Node *b)
{
    return a->weight >= b->weight;
}

//generate code of each node
void dfs(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        root->left->code = root->code + "0";
        dfs(root->left);
    }
    if (root->right)
    {
        root->right->code = root->code + "1";
        dfs(root->right);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[27];
    for (int i = 0; i < 27; ++i)
    {
        arr[i] = 0;
    }

    string str;
    getline(cin, str); //GET [ENTER]
    getline(cin, str);
    stringstream ss;
    ss << str;

    for (int i = 0; i < n; ++i)
    {
        char ch;
        ss >> ch;
        arr[ch - 'A']++;
    }
    vector<Node *> v;

    for (int i = 0; i < 27; ++i)
    {
        if (arr[i] != 0)
        {
            Node *new_node = new Node(i, arr[i]);
            v.push_back(new_node);
        }
    }
    sort(v.begin(), v.end(), cmp);
    /*
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << char((*it)->ch + 'A') << " " << (*it)->weight << endl;
    }
*/
    while (v.size() != 1)
    {
        Node *left = v.back();
        v.pop_back();
        Node *right = v.back();
        v.pop_back();
        v.push_back(new Node(left, right));
        sort(v.begin(), v.end(), cmp);
    }

    dfs(v.back());

    queue<Node *> q;
    q.push(v.back());
    v.pop_back();
    while (!q.empty())
    {
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL)
            q.push(q.front()->right);
        v.push_back(q.front());
        //cout << q.front()->code << endl;
        q.pop();
    }
/*
    //code for v1
    sort(v.begin(), v.end(), cmp);

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (0 <= (*it)->ch && (*it)->ch <= 25)
            cout << char((*it)->ch + 'A') << " " << (*it)->weight << " "
                 << (*it)->code << endl;
    }
*/
    //code for v3
    ss << str;

    char ch;
    int sum = 0;
    while (ss >> ch)
    {
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            if (char((*it)->ch + 'A') == ch)
            {
                sum += (*it)->code.length();
            }
        }
    }
    cout << sum << endl;

    //system("pause");
    return 0;
}