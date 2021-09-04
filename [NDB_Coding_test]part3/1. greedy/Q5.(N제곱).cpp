#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			int first = arr[i];
			int second = arr[j];
			if (first != second)
			{
				cnt++;
			}
		}
	}

	cout << cnt;
}