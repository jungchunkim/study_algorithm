#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//�ð� ����
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int count = 0;

	int hour = 0, minute = 0, second = 0;

	while (true)
	{
		second++;
		if (second == 60)
		{
			minute++;
			second = 0;
		}
		if (minute == 60)
		{
			hour++;
			minute = 0;
			if (hour == (N + 1))
			{// ��� �ð��� �Ѿ��� ��
				break;
			}
		}
		if (second / 10 == 3 || second % 10 == 3 || minute / 10 == 3 || minute % 10 == 3 || hour % 10 == 3)
		{
			count++;
		}

	}
	cout << count;
}