#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int brr[2000000];

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> point(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		max += arr[i];
	}

	int sum;

	int temp = n - 1;
	while (true)
	{
		
		point[temp--] = 1;
		sort(point.begin(), point.end());
		do{
			sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (point[i] == 1)
					sum += arr[i];
			}
			brr[sum] = 1;
			cout << point[n-3]<<point[n-2]<<point[n - 1] << endl;
		} while (next_permutation(point.begin(),point.end()));
		if (temp == -1)
			break;
	}

	for (int i = 1;; i++)
	{
		if (brr[i] != 1)
		{
			cout << i;
			break;
		}
	}
}
