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
	while (N != 1)
	{
		if (N%K == 0)
		{
			N = N / K;
		}
		else
		{
			N--;
		}
		count++;
	}
	cout << count;
}