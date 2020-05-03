#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int n,m;
	int count = 1;
	cin >> n;


	for (int i = 1;i <= n;i++)
	{
		cin >> m;
		arr[i] = m;
	}

	if (n == 1)
		cout << count;
	else
	{
		for (int i = 1;i <=n ;i++)
		{
			for (int j = 0;j <i ;j++)
			{
				if (arr[j] < arr[i])
				{
					if (dp[i] < dp[j] + 1)
						dp[i] = dp[j] + 1;
				}
			}
		}

		int max = 0;
		for (int i = 1;i <= n;i++)
		{
			if (max < dp[i])
				max = dp[i];
		}
		cout << max;
	}
	

}