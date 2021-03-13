#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	string s;
	int count = 0;
	

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		stack<char> arr;

		for (int j = 0; j < s.length(); j++)
		{
			if (arr.empty())
			{
				arr.push(s[j]);
			}
			else
			{
				if (arr.top() == s[j])
				{
					arr.pop();
				}
				else
				{
					arr.push(s[j]);
				}
			}
		}

		if (arr.empty())
		{
			count++;
		}
	}

	cout << count;
}