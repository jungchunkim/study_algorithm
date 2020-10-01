#include <iostream>

using namespace std;

int main()
{
	int N; 
	int min;
	
	int sol = 0;
	cin >> N;

	int *arr = new int[N - 1];
	int *brr = new int[N];

	for (int i = 0; i < N - 1; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> brr[i];
	}

	sol = arr[0] * brr[0];
	min = brr[0];
	for (int i = 1; i < N-1; i++)
	{
		if (brr[i] < min) {
			min = brr[i];
		}
		sol += min * arr[i];
	}
	
	cout << sol;
}