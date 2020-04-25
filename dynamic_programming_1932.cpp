#include <iostream>
using namespace std;

unsigned long num[500][500] = { 0 };
unsigned long sum[500][500] = { 0 };

int main() 
{
	int n;
	cin >> n;

	// 입력 받았다
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> num[i][j];
			if (sum[i][j - 1] > sum[i - 1][j])
				sum[i][j] = num[i][j] + sum[i][j - 1];
			else
				sum[i][j] = num[i][j] + sum[i - 1][j - 1];
		}
	}
	//합이 최대가 되는 경로
	//대각선으로만 움직여
	unsigned long max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < sum[n][i])
			max = sum[n][i];
	}

	cout << max;


}