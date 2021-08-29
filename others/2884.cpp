#include <iostream>

using namespace std;


int main()
{
	int H, M;
	cin >> H >> M;

	if (M < 45)
	{
		H--;
		if (H == -1)
		{
			H = 23;
		}
		M = 60 + (M - 45);
		cout << H << " " << M;
	}
	else
	{
		cout << H << " " << M - 45;
	}
}