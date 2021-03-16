#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int N;
	queue<int> arr;
	string s;
	int num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> num;
			arr.push(num);
		}
		else if (s == "front")
		{
			if (arr.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << arr.front() << "\n";
			}

		}
		else if (s == "back")
		{
			if (arr.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << arr.back() << "\n";
			}
		}
		else if (s == "pop")
		{
			if (arr.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << arr.front() << "\n";
				arr.pop();
			}
		}
		else if (s == "size")
		{
			cout << arr.size() << "\n";
		}
		else if (s == "empty")
		{
			if (arr.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
	}
}