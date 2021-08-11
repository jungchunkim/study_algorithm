#include <iostream>

using namespace std;

int main()
{
	int N;	// °Å½½·¯Áà¾ßÇÒ µ·
	int money[] = { 500,100,50,10 };
	cin >> N;

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (N / money[i] > 0)
		{
			sum += N / money[i];
			N %= money[i];
		}
	}
	cout << sum;
}