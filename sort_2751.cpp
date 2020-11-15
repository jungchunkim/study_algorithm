#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> arr;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	int before;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			cout << arr[i] << "\n";
		else
		{
			if (before != arr[i])
			{
				cout << arr[i] << "\n";
			}			
		}
		before = arr[i];
	}
}