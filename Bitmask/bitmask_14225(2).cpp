#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int brr[2000000];

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int sum;
	for (int i = 0; i < (1 << n); i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & 1 << j)
			{
				sum += arr[j];
			}
		}
		brr[sum] = 1;
	}

	for (int i = 1;; i++)
		if (brr[i] != 1)
		{
			cout << i;
			break;
		}
}