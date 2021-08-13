#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int N;
	cin >> N;

	// x,y 값 초기화
	int y = 1;
	int x = 1;

	string plans;
	// ignore 쓰는거! 
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
		{// 'L'일때
			if (y - 1 >= 0)
			{
				y--;
			}
		}

	}
	cout << x << " " << y;

}