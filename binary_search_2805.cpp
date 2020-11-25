#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	long long M;	//나무의 수 :N, 가져가려고 하는 나무의 길이 :M 
	cin >> N >> M;
	vector<long long> arr(N);

	long long max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	long long left = 1;
	long long right = max;
	long long mid;
	long long sol = 0;
	long long sum;

	while (left <= right)
	{
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] - mid > 0)
				sum += (arr[i] - mid);
		}
		if (sum >= M)
		{
			if (mid > sol)
				sol = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}

	cout << sol;
}