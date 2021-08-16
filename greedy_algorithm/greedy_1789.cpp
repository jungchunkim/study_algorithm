#include <iostream>

using namespace std;

int main()
{
	long long S;
	long long sum = 0;
	cin >> S;

	int N = 1;

	while (true)
	{
		sum += N;
		if (sum > S)
		{
			break;
		}
		else
		{
			N++;
		}
	}
	cout << N - 1;
}