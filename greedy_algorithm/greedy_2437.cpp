#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	cin >> N;
	int sum = 0;
	int temp = 0;
	int *arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	while (1)
	{
		if (sum + 2 < arr[temp] || temp==N)
		{
			break;
		}
		else
		{
			sum += arr[temp++];
		}
	}

	cout << sum + 1;

}