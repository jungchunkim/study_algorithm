#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int N;
	cin >> N;

	int min=0, sec=0, hour=0;

	int count = 0;
	while (true)
	{
		sec++;
		if (sec == 60)
		{
			sec = 0;
			min++;
		}

		if (min == 60)
		{
			min = 0;
			hour++;
			if (hour == (N + 1))
				break;
		}

		// 3�ִ� �� ����(sec�� �ִ� ��, hour �� �ִ� ��, min �� �ִ� �� ���)
		if ((sec % 10) == 3 || (sec / 10) == 3 || (min % 10) == 3 || (min / 10) == 3 || (hour % 10) == 3)
		{
			count++;
		}
	}

	cout << count;
}