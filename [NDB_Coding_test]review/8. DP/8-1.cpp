#include <iostream>

using namespace std;

int min(int a, int b)
{
	if (a >= b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	int count = 0;

	int arr[30001] = { 0 };

	int X;
	cin >> X;

	for (int i = 2; i <= X; i++)
	{
		arr[i] = arr[i - 1] + 1;

		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		if (i % 5 == 0)
			arr[i] = min(arr[i], arr[i / 5] + 1);
	}

	cout << arr[X];
}