#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int max = arr[N - 1] - arr[0];
	int left = 1;
	int right = max;
	int mid;
	int count;
	int ans=0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		count = 1;
		int last = arr[0];
		for (int i = 0; i < N; i++)
		{
			if (arr[i] - last >= mid)
			{
				count++;
				last = arr[i];
			}
		}
		if (count >= C)
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}
	cout << ans;
}