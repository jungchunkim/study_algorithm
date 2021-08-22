#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int arr[15] = { 0 };
	int brr[15] = { 0 };
	int dp[15] = { 0 };

	int Max_num = 0;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = a;
		brr[i] = b;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		int time = arr[i] + i;

		if (time <= N)
		{
			dp[i] = max(Max_num, dp[time] + brr[i]);
			Max_num = dp[i];
		}
		else
		{
			dp[i] = Max_num;
		}
	}

	cout << Max_num;
}