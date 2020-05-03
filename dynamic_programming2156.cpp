#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int n,m;
	cin >> n;
	int* arr = new int[n+1];
	int* dp = new int[n+1];

	for (int i = 1;i <= n;i++)
	{
		cin >> m;
		arr[i] = m;
	}
	arr[0] = 0;
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];

	if (n == 1 || n == 2)
		cout << dp[n];
	else
	{
		for (int i = 3;i <= n;i++)
		{
			dp[i] = max(dp[i-1],max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]));
		}
		cout << dp[n];
	}
}