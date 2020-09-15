#include <iostream>

using namespace std;

int main()
{
	int N;
	int num_5, num_3;
	int sum = 0;
	cin >> N;	// 설탕의 킬로그램 입력

	num_5 = N / 5;

	while (num_5 != -1)
	{

		if ((N - (num_5 * 5))%3==0)
		{
			num_3 = (N - (num_5 * 5)) / 3;
			break;
		}
		else
		{
			num_5--;
		}
	}

	if (num_3 * 3 + num_5 * 5 == N)
	{
		cout << num_3 + num_5;
	}
	else
	{
		cout << -1;
	}
	

}