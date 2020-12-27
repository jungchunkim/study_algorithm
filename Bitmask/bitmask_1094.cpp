#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int x = (1 << 7) - 1;

	int sol = 0;

	for (int i = 6; i >= 0; i--)
	{
		if (n < (1 << i))
			continue;
	
		n -= (1 << i);
		sol++;		
		cout << n << endl;
	}

	cout << sol;
}