#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int> front;
	vector<int> back;

	for (int i = 0; i < s.size(); i++)
	{
		if (i <= (s.size() / 2) - 1)
		{
			front.push_back(s[i] - '0');
		}
		else
		{
			back.push_back(s[i] - '0');
		}
	}

	int sum_front = 0;
	int sum_back = 0;

	for (int i = 0; i < front.size(); i++)
	{
		sum_front += front[i];
	}
	for (int i = 0; i < back.size(); i++)
	{
		sum_back += back[i];
	}

	if (sum_front == sum_back)
	{
		cout << "LUCKY";
	}
	else
	{
		cout << "READY";
	}
}
