#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	queue<int> arr;

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		arr.push(i);
	}

	cout << "<";
	while (1)
	{
		for (int i = 1; i < K; i++)
		{
			arr.push(arr.front());
			arr.pop();
		}
		cout << arr.front();
		arr.pop();
		if (arr.empty())
		{
			break;
		}
		else
		{
			cout << ", ";
		}
	}
	cout << ">";

}