#include <iostream>

using namespace std;

int b[1001];

int main()
{
	int n, a = 0;
	cin >> n;
	//초기값을 설정하자
	b[1] = 1;
	b[2] = 2;
	//dp 스럽게 풀어보자
	for (int i = 3; i <= n; i++)
	{
		b[i] = (b[i - 1] + b[i - 2]) % 10007;
	}

	cout << b[n];
}