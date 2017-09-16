#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int work_load, position;
        cin >> work_load >> position;
        priority_queue<int> prio_q;
        queue<int> q;
        queue<int> pos;
        for (int j = 0; j < work_load; ++j)
        {
            int prio;
            cin >> prio;
            q.push(prio);
            prio_q.push(prio);
            pos.push(j);
        }
        int count = 1;
        while (!q.empty())                      //queue not empty
        {
            if (q.front() == prio_q.top())      //prio meet
            {
                if (pos.front() != position)    //not your page
                    count++;                    //wait
                else                            //is your page
                    break;                      //go get it
            }
            else                                //prio do not meet
            {
                q.push(q.front());              //roll to the end of queue
                pos.push(pos.front());

                prio_q.push(prio_q.top());
            }
            prio_q.pop();                       //push&pop an element at the same time in prio queue will not change the queue
            
            pos.pop();
            q.pop();
        }
        cout << count << endl;
    }
    char ch;
    cin.get(ch);
    cin.get(ch);
    return 0;
}