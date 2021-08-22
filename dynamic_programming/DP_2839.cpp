#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(5001, 3000);

	arr[3] = 1;
	arr[5] = 1;
	
	int drr[] = { 3,5 };

	for (int i = 0; i < 2; i++)
	{
		for (int j = drr[i]; j <= N; j++)
		{
			if (arr[j - drr[i]] != 3000)
			{
				arr[j] = min(arr[j], arr[j - drr[i]] + 1);
			}
		}
	}

	if (arr[N] == 3000)
	{
		cout << -1;
	}
	else
	{
		cout << arr[N];
	}
}