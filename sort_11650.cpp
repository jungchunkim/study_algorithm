#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int a, b;
	vector<pair<int, int>> arr;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr.push_back(pair<int, int>(a, b));
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first <<" "<< arr[i].second << "\n";
	}
	

}