#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	string k;

	stack<char> arr;
	stack<char> brr;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		arr.push(s[i]);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> k;
		if (k[0] == 'P')
		{
			cin >> k;
			arr.push(k[0]);
		}
		else if (k[0] == 'L')
		{
			if (arr.empty() != 1)
			{
				brr.push(arr.top());
				arr.pop();
			}
		}
		else if (k[0] == 'D')
		{
			if (brr.empty() != 1)
			{
				arr.push(brr.top());
				brr.pop();
			}
		}
		else
		{// BÀÏ °æ¿ì
			if (arr.empty() != 1)
			{
				arr.pop();
			}
		}
	}
	
	while (arr.empty() != 1)
	{
		brr.push(arr.top());
		arr.pop();
	}
	
	while (brr.empty() != 1)
	{
		cout << brr.top();
		brr.pop();
	}
}