#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<string,int> a, pair<string,int> b)
{
	return a.second < b.second;
}

int main()
{
	int N;

	cin >> N;

	vector<pair<string, int>> v;

	for (int i = 0; i < N; i++)
	{
		string s;
		int num;
		cin >> s >> num;
		v.push_back({ s,num });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " ";
	}

}