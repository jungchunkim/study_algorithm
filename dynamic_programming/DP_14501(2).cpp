#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int arr[15] = { 0 };
	int brr[15] = { 0 };
	int dp[16] = { 0 };

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = a;
		brr[i] = b;
	}

	for (int i = 0; i < N; i++)
	{
		int time = i + arr[i];

		if (time <= N)
		{ 
			if (dp[i + arr[i]] < dp[i] + brr[i])
			{
				dp[i + arr[i]] = dp[i] + brr[i];

				for (int j = i + arr[i]; j <= N; j++)
				{
					if (dp[j] < dp[i + arr[i]])
					{
						dp[j] = dp[i + arr[i]];
					}
				}
			}
		}
	}

	cout << dp[N];
}