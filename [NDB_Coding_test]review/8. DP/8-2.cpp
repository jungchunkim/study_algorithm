#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int N;
	cin >> N;
	int arr[101] = { 0 };
	int arr_max[101] = { 0 };

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	arr_max[1] = arr[1];
	arr_max[2] = max(arr[1],arr[2]);

	for (int i = 4; i <= N; i++)
	{
		arr_max[i] = max((arr_max[i - 2] + arr[i]), (arr_max[i - 1]));
	}


	cout << arr_max[N];
}
