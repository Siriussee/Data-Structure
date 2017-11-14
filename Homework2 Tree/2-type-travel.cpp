//Your task is to implement binary tree traversal using both recursion and non-recursion.
#include <cstddef>
#include <iostream>
#include <stack>
using namespace std;
// root is a pointer to the root of the binary tree.
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
template <typename T>
void inorder_recursive(BinaryNode<T> *root, void (*visit)(T &x))
{
    if (root == NULL)
        return;
    inorder_recursive(root->left, visit);
    visit(root->elem);
    inorder_recursive(root->right, visit);
}

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder(BinaryNode<T> *root, void (*visit)(T &x))
{
    if (root == NULL)
        return;
    stack<BinaryNode<T> *> s;
    while (!s.empty() || root != NULL)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        if (!s.empty())
        {
            root = s.top();
            s.pop();
            visit(root->elem);
            root = root->right;
        }
    }
}
