#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> arr;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			arr.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (!arr.empty() && arr.top() != '(')
			{
				cout << arr.top();
				arr.pop();
			}
			arr.pop();
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!arr.empty() && (arr.top() == '*' || arr.top() == '/'))
			{ // 우선순위가 같을 때 뺌
				cout << arr.top();
				arr.pop();
			}
			arr.push(s[i]);
		}
		else if (s[i] == '-' || s[i] == '+')
		{//우선순위가 가장 낮아서 다 뺌!
			while (!arr.empty() && arr.top() != '(')
			{
				cout << arr.top();
				arr.pop();
			}
			arr.push(s[i]);
		}
		else
		{//알파벳인 경우 그냥 출력
			cout << s[i];
		}
	}

	while (!arr.empty())
	{
		cout << arr.top();
		arr.pop();
	}
}