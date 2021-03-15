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
			{ // �켱������ ���� �� ��
				cout << arr.top();
				arr.pop();
			}
			arr.push(s[i]);
		}
		else if (s[i] == '-' || s[i] == '+')
		{//�켱������ ���� ���Ƽ� �� ��!
			while (!arr.empty() && arr.top() != '(')
			{
				cout << arr.top();
				arr.pop();
			}
			arr.push(s[i]);
		}
		else
		{//���ĺ��� ��� �׳� ���
			cout << s[i];
		}
	}

	while (!arr.empty())
	{
		cout << arr.top();
		arr.pop();
	}
}