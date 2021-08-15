#include <iostream>
#include <string>

using namespace std;

int dx[] = { 2,2,-2,-2,1,-1,1,-1 };
int dy[] = { 1,-1,1,-1,2,2,-2,-2 };

int main()
{
	string s;
	cin >> s;

	int count = 0;


	int x = s[1] - '1';
	int y = s[0] - 'a';

	for (int i = 0; i < 8; i++)
	{
		if (x + dx[i] >= 0 && x + dx[i] < 8 && y + dy[i] >= 0 && y + dy[i] < 8)
		{
			count++;
		}
	}


	cout << count;
}