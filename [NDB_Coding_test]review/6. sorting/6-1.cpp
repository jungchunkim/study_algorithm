#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}