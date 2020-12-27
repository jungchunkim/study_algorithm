#include <iostream>
#define MOD 15746
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *num = new int[N+1];

	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i < N; i++)
	{
		num[i] = num[i - 2] + num[i - 1];

	}
	cout << num[N]%MOD;
	delete[]num;
}