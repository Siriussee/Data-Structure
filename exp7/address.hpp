#include <iostream>
#include <string>

using namespace std;

struct node
{
    string name;
    string sex;
    string id;
    string phone;
    node *next;
    node()
    {
        name = "";
        sex = "";
        id = "";
        phone = "";
        next = NULL;
    }
    node(string n, string s, string i, string p)
    {
        name = n;
        sex = s;
        id = i;
        phone = p;
        next = NULL;
    }
};

class Address
{
    node *hashTable[50];

    void insert_h(string n, string s, string i, string p)
    {
        node *new_node = new node(n, s, i, p);
        int sum = 0;
        for (int i = 0; i < n.length(); ++i)
            sum += (int)n[i];
        sum %= 50;
        if (hashTable[sum] == NULL)
            hashTable[sum] = new_node;

        else
        {
            node *curr = hashTable[sum];
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = new_node;
        }
    }
    bool find_h(string name)
    {
        int sum = 0;
        for (int i = 0; i < name.length(); ++i)
            sum += (int)name[i];
        sum %= 50;
        bool is_found = false;
        if (hashTable[sum] != NULL)
        {
            if (hashTable[sum]->name == name)
            {
                is_found = true;
                cout << "name\t\tsex\t\tstudentID\t\tphone" << endl;
                cout << hashTable[sum]->name << "\t\t" << hashTable[sum]->sex << "\t\t" << hashTable[sum]->id << "\t\t" << hashTable[sum]->phone << endl;
            }
            else
            {
                node *curr = hashTable[sum];
                while (curr->next != NULL)
                {
                    if (curr->next->name == name)
                    {
                        is_found = true;
                        cout << "name\t\tsex\t\tstudentID\t\tphone" << endl;
                        cout << curr->next->name << "\t\t" << curr->next->sex << "\t\t" << curr->next->id << "\t\t" << curr->next->phone << endl;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }
        return is_found;
    }

  public:
    Address()
    {
        for (int i = 0; i < 50; ++i)
            hashTable[i] = NULL;
        insert_h("test1", "male", "16340123", "131234567890");
        insert_h("test2", "male", "16367sdf83", "131234567890");
        insert_h("test3", "female", "1634540123", "131234567890");
        insert_h("test4", "male", "1633450123", "131234567890");
        insert_h("test5", "female", "16340123", "131234567890");
        insert_h("test12", "male", "16340123", "131234567890");
        insert_h("test13", "female", "16340112", "131234567890");
        insert_h("test14", "male", "1634234123", "131234567890");
        insert_h("test0", "female", "16340123", "131234567890");
        insert_h("test16666", "male", "16340123", "131234567890");
        insert_h("test6546", "female", "16340112", "131234567890");
        insert_h("test87999", "female", "16340123", "131234567890");
        insert_h("test181", "male", "16340123", "131234567890");
        insert_h("deleted", "female", "16340112", "131234567890");
    }

    void show()
    {
        cout << "--------------- Address -------------------" << endl;
        cout << "name\t\tsex\t\tstudentID\t\tphone" << endl;
        for (int i = 0; i < 50; ++i)
        {
            if (hashTable[i] != NULL)
            {
                cout << hashTable[i]->name << "\t\t" << hashTable[i]->sex << "\t\t" << hashTable[i]->id << "\t\t" << hashTable[i]->phone << endl;
                node *curr = hashTable[i];
                while (curr->next != NULL)
                {
                    cout << curr->next->name << "\t\t" << curr->next->sex << "\t\t" << curr->next->id << "\t\t" << curr->next->phone << "*" << endl;
                    curr = curr->next;
                }
            }
        }
        cout << "--------------- end of address -------------------" << endl;
    }
    void find()
    {
        string name;
        cout << "--------- find --------------" << endl
             << "name: " << flush;
        getline(cin, name);

        if (find_h(name))
            cout << "--------- found --------------" << endl;
        else
            cout << "--------- not found ----------" << endl;
    }
    void insert()
    {
        string name, sex, id, phone;
        cout << "--------- insert --------------" << endl
             << "name: " << flush;
        getline(cin, name);
        if (name.empty())
        {
            cout << "name cannot be empty" << endl;
            cout << "--------- insert fail -------------" << endl;
            return;
        }
        if (find_h(name))
        {
            cout << "name used" << endl;
            cout << "--------- insert fail -------------" << endl;
            return;
        }

        cout << "sex: " << flush;
        getline(cin, sex);

        cout << "id: " << flush;
        getline(cin, id);

        cout << "phone: " << flush;
        getline(cin, phone);

        insert_h(name, sex, id, phone);
        cout << "--------- insert success -------------" << endl;
        return;
    }
    void delete_p()
    {
        string name;
        cout << "--------- delete --------------" << endl
             << "name: " << flush;
        getline(cin, name);
        int sum = 0;
        for (int i = 0; i < name.length(); ++i)
            sum += (int)name[i];
        sum %= 50;
        bool is_found = false;
        if (hashTable[sum] != NULL)
        {
            if (hashTable[sum]->name == name)
            {
                is_found = true;
                node *curr = hashTable[sum];
                if (curr->next == NULL)
                    hashTable[sum] = NULL;
                else
                    hashTable[sum] = hashTable[sum]->next;

            }
            else
            {
                node *curr = hashTable[sum];
                while (curr->next != NULL)
                {
                    if (curr->next->name == name)
                    {
                        is_found = true;
                        node *to_be_del = curr->next;
                        curr->next = to_be_del->next;
                        delete to_be_del;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }
        if (is_found)
            cout << "--------- delete success--------------" << endl;
        else
            cout << "--------- delete fail--------------" << endl;
    }
};