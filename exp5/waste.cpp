 /*
    void PrintNodeByLevel(Node *root)
    {
        int parentSize = 1, childSize = 0;
        int space = 8;
        Node *temp;
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
                childSize++;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                childSize++;
            }
            parentSize--;
            // if current is empty, to next line

            if (parentSize == 0)
            {
                parentSize = childSize;
                childSize = 0;
                cout << endl;
                for (int i = space; i > 0; --i)
                {
                    cout << "  ";
                }
                space--;
            }

        } while (!q.empty());
    }*/