#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
int max_top = 0, min_top = 0;
void check(int num, vector<stack<int>> &store, vector<int> &result, int &p);
void clear(int &number, vector<stack<int>> &store, vector<int> &result);
int move(vector<stack<int>> &store, int number);
void randomGenerate(int size, int *arr);
int main()
{
    cout << "Please input the number of the train" << endl;
    int n;
    int p = 1;
    cin >> n;
    int arr[n];

    vector<stack<int>> store;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        check(arr[i], store, result, p);
        cout << "---tmp-----" << endl;
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }

    /*randomGenerate(n, arr);
 cout << "-------------Check random number----------------" << endl;
 for(int i = 0; i < n; i++){
     cout << arr[i] << " ";
 }
 cout << endl;
 cout << "------------------------------------------------" << endl;
 for(int i = 0; i < n; i++){
     check(arr[i], store, result, p);
     cout << "---tmp-----"<< endl;
     for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;

 }*/

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}

//

void check(int num, vector<stack<int>> &store, vector<int> &result, int &p)
{
    bool flag_in = 0;
    bool flag2 = 0;
    int index, dis, tmp;
    cout << num << endl;

    if (num == p)
    {

        cout << num << " MOVE DIRECTLY FROM RUGUI TO CHUGUI" << endl;
        result.push_back(num);
        p = p + 1;
        clear(p, store, result);
        move(store);
        return;
    }
    else
    {

        for (int i = 0; i < store.size(); i++)
        {
            if (store[i].empty())
            { ///???
                store[i].push(num);
                cout << num << " enter the empty stack NO." << i << endl;
                //move(store); **************************
                //break;
                return;
            }
            if (num < store[i].top())
            {
                //flag = 1;
                store[i].push(num);
                //move(store); **********
                cout << "STACK NO." << i << " NUM " << num << endl;
                return;
            }
        }

        int zancunmove = move(store, num);
        if (zancunmove != -1)
        {
            store[zancunmove].push(num);
            cout << "STACK NO." << zancunmove << " NUM" << num << endl;
            return;
        }

        stack<int> temp;
        temp.push(num);
        store.push_back(temp);
        cout << "-----NEW STACK-----" << endl;
        cout << "push " << num << " in new stack NO." << store.size() - 1 << endl;
        //move(store); *********
    }
}

/*stack<int> temp;
  temp.push(num);
  max_top = num;
  if(!store.empty()) min_top = store[store.size()-1].top();

  cout << "TEST FOR TOP NUMBER" << endl;
  cout << "max top " << max_top << " min top " << min_top << endl;


  store.push_back(temp);
  cout << "----NEW STACK!----" << endl;
  int tmpno = store.size()-1;
  cout << "STACK NO." << tmpno << " NUM " << num << endl;*/

void clear(int &number, vector<stack<int>> &store, vector<int> &result)
{

    //not so good
    cout << "storesize " << store.size() << endl;
    for (int i = 0; i < store.size(); i++)
    {
        if (!(store[i].empty()) && store[i].top() == number)
        {
            result.push_back(store[i].top());
            int tmpp = store[i].top();
            cout << tmpp << " POP FROM NO." << i << endl;
            store[i].pop();
            number++;

            clear(number, store, result);
        }
    }
}

int move(vector<stack<int>> &store, int number)
{
    for (int i = 0; i < store.size(); i++)
    {
        int zancun = 0;
        if (store[i].empty())
            continue;
        int record = store[i].top();
        store[i].pop();
        if (!store[i].empty())
        {
            zancun = store[i].top();
        }

        store[i].push(record);
        for (int j = i + 1; j < store.size(); j++)
        {
            if (store[j].empty())
                continue;

            if (record < store[j].top() && (store[i].size() == 1 || number < zancun))
            {
                store[j].push(record);
                store[i].pop();
                cout << record << " MOVES FROM NO." << i << " TO NO." << j << endl;
                return i;
            }
        }
    }

    return -1;
}

/*void move(vector<stack<int>>& store, int number){
    for(int i = 0; i < store.size(); i++){
        if(store[i].empty()) continue;
        int record = store[i].top();
        store[i].pop();
        int zancun = store[i].top();
        store[i].push(record);
        for(int j = i+1; j < store.size(); j++){
            if(store[j].empty()) continue;
            
            if(record < store[j].top() && (store[i].size() || number < zancun)){
                store[j].push(record);
                store[i].pop();
                cout << record << " MOVES FROM NO." << i << " TO NO." << j << endl;
                return;
            }
        }
    }
}*/

void randomGenerate(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    random_shuffle(arr, arr + size);
}

//测试用例
//#1
/*9
2 4 5 3 9 1 7 6 8
*/
/*用原方法是4个栈，改用移动法是3个栈*/

//#test 2
/*9
2 5 7 4 6 3 8 9 1
maybe 4*/

//test 3
/*9
4 7 2 8 1 9 3 6 5
==>2*/

//test 4
/*20
 13 18 4 20 16 1 17 6 7 15 19 5 11 12 8 9 10 14 2 3*/
//==>5