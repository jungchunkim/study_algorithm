#include <iostream>

using namespace std;

int d[1000];

int main()
{
	int N;
	cin >> N;

	d[0] = 1;
	d[1] = 3;

	for (int i = 2; i < N; i++)
	{
		d[i] = (2 * d[i - 2] + d[i - 1]) % 796796;
	}

	cout << d[N - 1];

}