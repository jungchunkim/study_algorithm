#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int num;
	queue<int> arr;

	for (int i = 1; i <= N; i++)
	{
		arr.push(i);
	}

	while (1)
	{
		num = arr.front();
		arr.pop();
		if (arr.empty())
		{
			cout << num;
			break;
		}
		else
		{
			arr.push(arr.front());
			arr.pop();
		}
		
	}

}