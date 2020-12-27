#include <iostream>
using namespace std;

unsigned long d[101];

int main()
{
	int N, K;
	cin >> N; // 테스트 케이스의 개수

	unsigned long *num = new unsigned long[N];
	d[0] = 1;
	d[1] = 1;
	d[2] = 1;

	for (int i = 3; i <= 100; i++)
		d[i] = d[i - 2] + d[i - 3];

	for (int i = 0; i < N; i++)
	{
		cin >> K;
		num[i] = d[K - 1];
	}
	for (int i = 0; i < N; i++)
		cout << num[i] << endl;
}