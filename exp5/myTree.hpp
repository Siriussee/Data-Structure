#include <iostream>
#include <queue>
#include <deque>
#include <cctype>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
    Node(char d)
    {
        data = d;
        left = right = NULL;
    }
};
class myTree
{
  private:
    Node *head;
    static int count;

  public:
    myTree()
    {
        head = NULL;
    }
    void insert(char d)
    {
        if (!isalpha(d))
        {
            cout << "invaild input data form" << endl;
            return;
        }
        Node *newNode;
        newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *curr = head;
        while (1)
        {
            if (d >= curr->data && curr->left == NULL)
            {
                curr->left = newNode;
                break;
            }
            if (d >= curr->data && curr->left != NULL)
                curr = curr->left;

            if (d < curr->data && curr->right == NULL)
            {
                curr->right = newNode;
                break;
            }
            if (d < curr->data && curr->right != NULL)
                curr = curr->right;
        }
    }
    void PrintNodeByLevel(Node *n, int level)
    {
        if (n == NULL)
            return;
        PrintNodeByLevel(n->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << n->data << endl;
        PrintNodeByLevel(n->right, level + 1);
    }

    void print()
    {
        if (head == NULL)
            return;
        PrintNodeByLevel(head, 0);
        return;
    }

    void reverseTree()
    {
        if (head == NULL)
            return;
        reverse(head);
    }
    void reverse(Node *root)
    {
        if (root->left != NULL)
            reverse(root->left);
        if (root->right != NULL)
            reverse(root->right);
        reverseANode(root);
    }
    void reverseANode(Node *n)
    {
        if (n->left != NULL || n->right != NULL)
        {
            Node *temp = n->left;
            n->left = n->right;
            n->right = temp;
        }
    }
};
