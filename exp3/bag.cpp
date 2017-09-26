#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int is_full(stack<int> s, int c)    // return 0 if exactly meet, 1 if overweighted
{
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    if (sum == c)
        return 0;
    if (sum > c)
        return 1;
    return -1;
}

int main()
{
    cout << "What is the capacity of the bag?" << endl;
    int c;
    cin >> c;
    cout << "how many item do you have?" << endl;
    int t;
    cin >> t;
    cout << "please enter the weight of each item, saparated by space" << endl;
    vector<int> vec;
    int w;
    for (int i = 0; i < t; ++i)
    {
        cin >> w;
        vec.push_back(w);
    }

    sort(vec.begin(), vec.end());   //sort to reduce further discussion

    cout << "the possible solutions are listed:" << endl;
    
    for (int i = 0; i < t; ++i)
    {
        //int count = i;
        stack<int> c_s;     //to store the index
        stack<int> s;       //to store weight of item
        
        for (int j = i; j < t; )
        {
            s.push(vec[j]);
            c_s.push(j);
            j++;
            //j = count;
            if (is_full(s, c) == 1) //if overweighted
            {
                s.pop();                //pop 2 from weight stack
                s.pop();
                c_s.pop();              //pop 2 from index stack
                j = c_s.top() + 1;      //remember the seconde last index. 
                                        //+1 is to mark the weight you should add the next round.
                c_s.pop();
                continue;
            }
            if(is_full(s,c) == 0)
            {
                stack<int> s_copy = s;
                while(!s_copy.empty())
                {

                    cout << s_copy.top() << " ";
                    s_copy.pop();
                }
                cout << endl;
                
                s.pop();               //almost the same to the former occasion
                s.pop();
                c_s.pop();
                j = c_s.top() + 1;
                c_s.pop();
                
            }
        }
    }
    system("pause");
    return 0;
}

