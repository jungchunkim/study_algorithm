#include <iostream>
#include <algorithm>

using namespace std;

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main()
{
	// 그리디 알고리즘 : 가능한 경우의 수를 모두 세어주는 것으로 시작하자.
	int N, M;

	cin >> N >> M;

	if (N == 1)
		cout << 1;
	else if (N == 2)
		cout << min(4, (1 + M) / 2);
	else
	{
		//N이 3 이상일 때, width 크기 마다 달라져
		if (M > 7)
			cout << 4 + (M - 7);
		else
			cout << min(4, M);
	}
}