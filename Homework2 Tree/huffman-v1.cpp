#include <iostream>
#include <algorithm>
#include <vector>
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
        ch = a->ch + b->ch;
        weight = a->weight + b->weight;
        left = a;
        right = b;
    }
};

//from big to small
bool cmp(Node *a, Node *b)
{
    return a->weight > b->weight;
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
    getline(cin,str); //GET [ENTER]
    getline(cin,str);
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

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << char((*it)->ch + 'A') << " " << (*it)->weight << endl;
    }

    
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

    ss << str;

    char ch;
    int sum = 0;
    while(ss >> ch)
    {
        sum += code_length(v.back(),ch);
    }

    system("pause");
    return 0;
}