#include <iostream>
#include <queue>

using namespace std;
/*
template <typename T>
struct BinaryNode
{
    T elem;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(T d, BinaryNode *l = NULL, BinaryNode *r = NULL) : elem(d), left(l), right(r){};
};
*/
//Your task is to implement the level traversal of binary trees.

// root is a pointer to the root of the binary tree.

template <typename T>
void levelTraversal(BinaryNode<T> *root, void (*visit)(T &x))
{
    if (root == NULL)
        return;
    queue<BinaryNode<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL)
            q.push(q.front()->right);
        visit(q.front()->elem);
        q.pop();
    }
}