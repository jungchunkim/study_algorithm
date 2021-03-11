#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> arr;
	int sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			arr.push('(');
		}
		else
		{// ) 일 때
			if (s[i - 1] == '(')
			{// 전의 값이 ( 일 때
				arr.pop();
				sum += arr.size();
			}
			else
			{// 전의 값이 ) 일 때
				sum++;
				arr.pop();
			}
		}
	}

	cout << sum;
}