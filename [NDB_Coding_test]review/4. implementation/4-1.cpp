#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int N;
	cin >> N;

	// x,y �� �ʱ�ȭ
	int y = 1;
	int x = 1;

	string plans;
	// ignore ���°�! 
	cin.ignore();
	getline(cin, plans);

	char dir;

	for (int i = 0; i < plans.size(); i++)
	{
		dir = plans[i];

		if (dir == ' ')
			continue;

		if (dir == 'R')
		{
			if (y + 1 <= N)
			{
				y++;
			}
		}
		else if (dir == 'U')
		{
			if ((x - 1) != 0)
			{
				x--;
			}
		}
		else if (dir == 'D')
		{
			if (x + 1 <= N)
			{
				x++;
			}
		}
		else
		{// 'L'�϶�
			if (y - 1 >= 0)
			{
				y--;
			}
		}

	}
	cout << x << " " << y;

}