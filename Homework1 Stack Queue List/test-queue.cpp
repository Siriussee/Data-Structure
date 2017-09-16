#include <iostream>
#include <queue>
#include <vector>         // std::vector

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n,m;
		cin >> n >> m;
		queue<int> num;
		for(int j = 0 ; j < n; ++j)
		{
			num.push(j);
		}
		//n is the number of jobs in the queue (1 ≤ n ≤ 50)
		//m is the position of your job (0 ≤ m ≤ n −1)
		queue<int> ns_prio;
		priority_queue<int> s_prio;
		for (int j = 0; j < n; ++j)
		{
			int prio;
			cin >>  prio;
			ns_prio.push(prio);
			s_prio.push(prio);
		}
		//queue<int> s_num;
		int count = 1;
		while(!num.empty())
		{
			if(ns_prio.front() == s_prio.top())
			{
				//s_num.push(num.top());
				if(num.front() != m)
					count++;
				else
					break;
			}
			else
			{
				num.push(num.front());
				s_prio.push(s_prio.top());
				ns_prio.push(ns_prio.front());
			}
			num.pop();
			s_prio.pop();
			ns_prio.pop();
		}
		cout << count <<endl;
	}
	return 0;
}