#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b)
{
	if (a.first.second > b.first.second)
	{
		return true;
	}
	else
	{
		if (a.first.second == b.first.second)
		{
			if (a.second.first < b.second.first)
			{
				return true;
			}
			else
			{
				if (a.second.first == b.second.first)
				{
					if (a.second.second > b.second.second)
					{
						return true;
					}
					else
					{
						if (a.second.second == b.second.second)
						{
							if (a.first.first < b.first.first)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<pair<pair<string, int>, pair<int, int>>> arr;
	for (int i = 0; i < N; i++)
	{
		string s;
		int a, b, c;

		cin >> s >> a >> b >> c;

		arr.push_back({ {s,a},{b,c} });
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first.first << "\n";
	}
}