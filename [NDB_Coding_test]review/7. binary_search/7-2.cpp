#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int N, M;

void BinarySearch(int start, int end)
{
	int result=0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > mid)
			{
				sum += arr[i] - mid;
			}
		}
		if (sum < M)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
			result = mid;
		}
	}
	cout << result;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	BinarySearch(arr[0], arr[N - 1]);
}