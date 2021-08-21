#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int count = 0;

	vector<int> arr;

	for (int i = 0; i < s.size(); i++)
	{
		int num = s[i] - '0';
		arr.push_back(num);
	}


	int prev = arr[0];
	int count_0 = 0;
	int count_1 = 0;
	if (prev == 0)
	{
		count_0++;
	}
	else
	{
		count_1++;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (prev != arr[i])
		{
			if (arr[i] == 0)
			{
				count_0++;
			}
			else
			{
				count_1++;
			}
			prev = arr[i];
		}
	}

	cout << min(count_0, count_1);
}