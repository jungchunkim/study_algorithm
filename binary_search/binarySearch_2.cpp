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
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int start = arr[0];
	int mid;
	int end = arr[N - 1];

	while (1)
	{
		mid = (start + end) / 2;

		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > mid)
			{
				sum += arr[i] - mid;
			}
		}
		if (sum == M)
		{
			cout << mid;
			break;
		}
		else if (sum > M)
		{// sum 이 더 클 때
			start = mid + 1;
		}
		else
		{// sum 이 더 작을 때
			end = mid - 1;
		}

	}
}