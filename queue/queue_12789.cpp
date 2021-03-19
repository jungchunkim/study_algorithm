#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> arr;
	stack<int> brr;
	int N;
	cin >> N;

	int num;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		arr.push(num);
	}

	int index = 1;
	while (arr.empty() != 1)
	{
		if (arr.front() == index)
		{//arr 에 있을 때
			index++;
			arr.pop();
		}
		else
		{
			if (brr.empty() != 1 && brr.top() == index)
			{

				index++;
				brr.pop();

			}
			else
			{// 순서가 아닐 때
				brr.push(arr.front());
				arr.pop();
			}
		}
	}

	while (brr.empty() != 1)
	{
		if (brr.top() == index)
		{
			brr.pop();
			index++;
		}
		else
		{
			cout << "Sad";
			return 0;
		}
	}
	cout << "Nice";

}