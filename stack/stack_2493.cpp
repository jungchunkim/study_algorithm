#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;

	stack<pair<int, int>> arr;

	cin >> N;

	int num;
	int index = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (arr.empty())
		{
			cout << "0 ";
		}
		else
		{
			if (arr.top().second > num)
			{
				cout << arr.top().first<<" ";
			}
			else
			{
				while (!arr.empty())
				{
					
					if (arr.top().second > num)
					{
						cout << arr.top().first << " ";			
						break;
					}
					arr.pop();
				}
				if (arr.empty())
				{
					cout << "0 ";
				}

			}
		}
		arr.push(make_pair(index, num));
		index++;

	}
}