#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int ans = 0;

	while (N != 1)
	{
		if (N%K == 0)
		{
			N = N / K;
			ans++;
		}
		else
		{
			N--;
			ans++;
		}
	}

	cout << ans;
}