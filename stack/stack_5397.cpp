#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;	

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		stack<char> arr;
		stack<char> brr;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '<')
			{
				if (arr.empty() != 1)
				{
					brr.push(arr.top());
					arr.pop();
				}
			}
			else if (s[j] == '>')
			{
				if (brr.empty() != 1)
				{
					arr.push(brr.top());
					brr.pop();
				}
			}
			else if (s[j] == '-')
			{
				if (!arr.empty())
					arr.pop();
			}
			else
			{
				arr.push(s[j]);
			}

		}

		while (!arr.empty())
		{
			brr.push(arr.top());
			arr.pop();
		}

		while(!brr.empty())
		{
			cout << brr.top();
			brr.pop();
		}
		cout << "\n";
	}

}