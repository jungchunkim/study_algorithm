#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long X, Y;
	long tmp = 0;

	cin >> X >> Y;
	cout << sizeof(int) << sizeof(long);
	long *arr = new long[X];
	for (int i = 0; i < X; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < Y; i++)
	{
		sort(arr, arr + X);
		tmp = arr[0] + arr[1];
		arr[0] = tmp;
		arr[1] = tmp;
	}
	long sum=0;

	for (int i = 0; i < X; i++)
	{
		sum += arr[i];
	}
	cout << sum;

}