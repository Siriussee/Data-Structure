#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i > 10; ++i)
    {
        q.push(i);
        pq.push(i);
    }
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    char ch;
    ch = cin.get();
    return 0;
}