#include <iostream>

using namespace std;

int main()
{
	int arr[1001];
	int N;
	cin >> N;

	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= N; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 796796;
	}

	cout << arr[N];
}