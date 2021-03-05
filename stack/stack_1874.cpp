#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n;	// 입력할 숫자 개수 
	int num; // 입력할 숫자
	int index = 0;

	stack<int> s;
	vector<int> arr;
	vector<char> arr_char;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	int i = 1;

	while (index < n && i!=(n+2))
	{
		if (s.empty())
		{
			s.push(i++);
			arr_char.push_back('+');
		}
		else if (s.top() == arr[index])
		{
			s.pop();
			arr_char.push_back('-');
			index++;
		}
		else
		{
			s.push(i++);
			arr_char.push_back('+');
		}
	}

	if (i == (n + 2))
	{
		for (int i = 0; i < arr_char.size(); i++)
		{
			cout << arr_char[i] << "\n";
		}
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < arr_char.size(); i++)
		{
			cout << arr_char[i] << "\n";
		}
	}
}