#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int> arr;
	for (int i = 0; i < s.size(); i++)
	{
		arr.push_back(s[i] - '0');
	}

	int count = 0;

	int first = arr[0];

	
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != first && arr[i - 1] == first)
		{
			count++;
		}
	}

	cout << count;
}