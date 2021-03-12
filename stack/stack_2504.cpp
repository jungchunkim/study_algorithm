#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	stack<char> arr;

	int num = 1;
	int sum = 0;
	bool a = true;

	cin >> s;

	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == '(')
		{
			arr.push(s[i]);
			num *= 2;
		}
		else if (s[i] == '[')
		{
			arr.push(s[i]);
			num *= 3;
		}
		else if (s[i] == ')')
		{
			if (arr.empty())
			{
				a = false;
				break;
			}
			else
			{
				if (s[i - 1] == '(')
				{
					sum += num;
				}
				arr.pop();
				num /= 2;
			}
		}
		else if (s[i] == ']')
		{
			if (arr.empty())
			{
				a = false;
				break;
			}
			else
			{
				if (s[i - 1] == '[')
				{
					sum += num;
				}
				arr.pop();
				num /= 3;
			}
		}
	}

	if (a && arr.empty())
	{
		cout << sum;
	}
	else
	{
		cout << 0;
	}
}