#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	int N;
	int T;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> T;
		char var;
		deque<char> brr;
		
		for (int j = 0; j < T; j++)
		{
			cin >> var;
			if (brr.empty())
			{
				brr.push_back(var);
			}
			else
			{
				if (brr.front() < var)
				{
					brr.push_back(var);
				}
				else
				{
					brr.push_front(var);
				}
			}
		}

		for (int j = 0; j < T; j++)
		{
			cout << brr.front();
			brr.pop_front();
		}
		cout << "\n";

	}
}