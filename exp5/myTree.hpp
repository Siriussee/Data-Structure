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
        if(head == NULL)
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
            {
                curr = curr->left;
            }
            if (d < curr->data && curr->right == NULL)
            {
                curr->right = newNode;
                break;
            }
            if (d < curr->data && curr->right != NULL)
            {
                curr = curr->right;
            }
        }
    }
    void print()
    {
        PrintNodeByLevel(head);
        return;
    }

    void PrintNodeByLevel(Node *root)  
    {  
        int parentSize = 1, childSize = 0; 
        int space = 8; 
        Node * temp;  
        queue<Node *> q;  
        q.push(root);  
        cout << "                  ";
        do  
        {  
            //print current line
            temp = q.front();         
            cout << temp->data << "    ";  
            q.pop();  
      
            if (temp->left != NULL)   
            {  
                q.push(temp->left);  
                childSize ++;  
            }  
            if (temp->right != NULL)   
            {  
                q.push(temp->right);  
                childSize ++;  
            }  
            parentSize--; 
            // if current is empty, to next line
            
            if (parentSize == 0)   
            {  
                parentSize = childSize;  
                childSize = 0;  
                cout << endl;
                for(int i = space; i > 0; --i)
                {
                    cout << "  ";
                }
                space--;  
            }  
      
        } while (!q.empty());  
    }  
    void reverseTree()
    {
        reverse(head);
    }
    void reverse(Node* root)
    {
        if(root->left != NULL)
            reverse(root->left);
        if(root->right != NULL)
            reverse(root->right);
        reverseANode(root);
    }
    void reverseANode(Node * n)
    {
        if(n->left != NULL || n->right != NULL)
        {
            Node* temp =  n->left;
            n->left = n->right;
            n->right = temp;
        }
    }
};