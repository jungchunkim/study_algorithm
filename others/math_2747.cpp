#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[45];

int main()
{
	int n;
	cin >> n;

	d[1] = 1;

	for (int i = 2; i <= n; i ++ )
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n];
}