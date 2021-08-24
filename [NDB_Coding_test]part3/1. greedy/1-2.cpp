#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main()
{
	string s;
	cin >> s;

	vector<int> arr(20);

	for (int i = 0; i < s.size(); i++)
	{
		arr[i] = s[i] - '0';
	}

	int sum = arr[0];
	
	bool is_num = false;

	if (sum == 0 || sum == 1)
	{
		is_num = true;
	}
	
	for (int i = 1; i < arr.size(); i++)
	{
		if (i == 1 && is_num == true)
		{
			sum += arr[i];
		}
		else
		{
			if (arr[i] == 1 || arr[i] == 0)
			{
				sum += arr[i];
			}
			else
			{
				sum *= arr[i];
			}
		}
	}
	cout << sum;
}