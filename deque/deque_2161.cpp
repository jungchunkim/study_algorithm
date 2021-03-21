#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int N;
	cin >> N;
	deque<int> dq;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	while (1)
	{
		cout << dq.front() << " ";
		dq.pop_front();
		if (dq.empty())
		{
			break;
		}
		else
		{
			dq.push_back(dq.front());
			dq.pop_front();
		}
		
	}
}