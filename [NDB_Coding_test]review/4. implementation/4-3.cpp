<<<<<<< HEAD
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int count = 0;


	int x = s[1] - '1';
	int y = s[0] - 'a';

	//1번 경우
	if ((x + 2) < 8)
	{
		if (y + 1 < 8)
		{
			count++;
		}
		if (y - 1 >= 0)
		{
			count++;
		}
	}
	if ((x - 2) >= 0)
	{
		if (y + 1 < 8)
		{
			count++;
		}
		if (y - 1 >= 0)
		{
			count++;
		}
	}

	//2번 경우
	if (y + 2 < 8)
	{
		if (x + 1 < 8)
		{
			count++;
		}
		if (x - 1 >= 0)
		{
			count++;
		}
	}

	if (y - 2 >= 0)
	{
		if (x + 1 < 8)
		{
			count++;
		}
		if (x - 1 >= 0)
		{
			count++;
		}
	}


	cout << count;
=======
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int count = 0;


	int x = s[1] - '1';
	int y = s[0] - 'a';

	//1번 경우
	if ((x + 2) < 8)
	{
		if (y + 1 < 8)
		{
			count++;
		}
		if (y - 1 >= 0)
		{
			count++;
		}
	}
	if ((x - 2) >= 0)
	{
		if (y + 1 < 8)
		{
			count++;
		}
		if (y - 1 >= 0)
		{
			count++;
		}
	}

	//2번 경우
	if (y + 2 < 8)
	{
		if (x + 1 < 8)
		{
			count++;
		}
		if (x - 1 >= 0)
		{
			count++;
		}
	}

	if (y - 2 >= 0)
	{
		if (x + 1 < 8)
		{
			count++;
		}
		if (x - 1 >= 0)
		{
			count++;
		}
	}


	cout << count;
>>>>>>> 611ec6963bc9f55325e48791ff01a1bda620ee17
}