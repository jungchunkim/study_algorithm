#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> arr;

	for (int i = 0; i < 7; i++)
	{
		int num;
		cin >> num;

		if (num % 2 != 0)
		{
			arr.push_back(num);
		}
	}

	if (arr.size() == 0)
	{
		cout << -1;
	}
	else
	{
		int sum = 0;
		int min_num = arr[0];
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];
			min_num = min(min_num, arr[i]);
		}

		cout << sum << "\n" << min_num;
	}
	

}