#include <iostream>
#include <math.h>
using namespace std;


int main() {
	int M, N;
	cin >> M >> N;

	int sum = 0;
	int first = 0;
	for (int i = M; i <= N; i++)
	{
		int flag = 1;
		if (i <= 1)
		{
			flag = 0;
		}
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0 )
			{
				flag = 0;
				break;
			}
		}
		if (flag != 0)
		{
			if (sum == 0)
			{
				first = i;
			}
			sum += i;
		}

	}
	if (sum > 0)
	{
		cout << sum << "\n" << first;
	}
	else
	{
		cout << -1;
	}
}