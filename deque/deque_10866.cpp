#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string s;
	int num;
	deque<int> arr;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> num;
			arr.push_front(num);
		}
		else if (s == "push_back")
		{
			cin >> num;
			arr.push_back(num);
		}
		else if (s == "pop_front")
		{
			if (arr.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << arr.front() << "\n";
				arr.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (arr.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << arr.back() << "\n";
				arr.pop_back();
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
	}
}