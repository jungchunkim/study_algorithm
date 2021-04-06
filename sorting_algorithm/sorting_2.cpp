#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}


int main()
{
	int N;
	cin >> N;

	vector<pair<string, int>> arr;

	for (int i = 0; i < N; i++)
	{
		string s;
		int num;
		cin >> s >> num;
		arr.push_back(make_pair(s, num));
	}

	sort(arr.begin(), arr.end(),cmp);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first<< " ";
	}

}