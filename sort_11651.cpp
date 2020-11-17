#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> arr;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first <<" "<< arr[i].second << "\n";
	}
}