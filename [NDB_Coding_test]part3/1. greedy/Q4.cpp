#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int main(void) 
{
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	int target = 1;

	for (int i = 0; i < n; i++) 
	{
		if (target < arr[i]) 
			break;

		target += arr[i];
	}

	cout << target << '\n';
}