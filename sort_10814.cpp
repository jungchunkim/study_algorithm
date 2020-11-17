#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
	if (a.first < b.first)
	{
		return true;
	}
	else if (a.first == b.first)
	{
		if (a.second.first < b.second.first)
			return true;
		else
			return false;
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
	int a;
	string s;
	vector<pair<int,pair<int, string>>> arr;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> s;
		arr.push_back(make_pair(a, make_pair(i, s)));
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second.second << "\n";
	}
}