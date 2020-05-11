#include <iostream>
using namespace std;



int main() 
{
	int n, k, l;
	int count = 0;
	cin >> n >> k;

	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		arr[i] = l;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (k == 0)
			break;
		while (1)
		{
			if (k >= arr[i])
			{
				k = k - arr[i];
				count++;
			}
			else
				break;
		}
	}

	cout << count;
}