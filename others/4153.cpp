#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;

	while(true)
	{
		cin >> a >> b >> c;
		int arr[] = { a,b,c };

		sort(arr, arr + 3);
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		else
		{
			if ((arr[0]*arr[0] + arr[1] * arr[1]) == arr[2] * arr[2])
			{
				cout << "right\n";
			}
			else
			{
				cout << "wrong\n";
			}
		}
	}
}