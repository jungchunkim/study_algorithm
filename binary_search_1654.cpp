#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int K, N;
	cin >> K >> N;
	vector<int> arr(K);
	long long max=0;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	long long left = 1;
	long long right = max;
	long long x;
	long long sol;
	long long ans = 0;
	while (left <= right)
	{
		x = (left + right) / 2;
		sol = 0;
		for (int i = 0; i < K; i++)
		{
			sol += arr[i] / x;
		}
		if (sol >= N)
		{
			if (ans < x)
				ans = x;
			left = x + 1;
		}
		else
		{
			right = x - 1;
		}

	}

	cout << ans;
}