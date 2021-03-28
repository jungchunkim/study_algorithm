#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//1이 될 때 까지 문제
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int count = 0;
	int num;
	while (N != 1)
	{
		num = N % K;

		if (num == 0)
		{
			N = N / K;
			count++;
		}
		else
		{
			N -= num;
			count += num;
		}
	}
	cout << count;
}