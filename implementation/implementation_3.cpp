#include <iostream>
#include <string>
#include <vector>

using namespace std;


int dx[] = { 2,2,1,-1,1,-1,-2,-2 };
int dy[] = { 1,-1,2,2,-2,-2,1,-1 };

int main()
{
	string s;
	cin >> s;

	int x = (s[0] - 'a') + 1;
	int y = (s[1] - '0');
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		int x_1, y_1;
		x_1 = x + dx[i];
		y_1 = y + dy[i];

		if (x_1 > 8 || y_1 > 8 || x_1 < 1 || y_1 < 1)
		{
			continue;
		}
		else
		{
			count++;
		}
	}

	cout << count;
}