#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	string a;
	vector<int> arr;

	cin >> a;

	for (int i = 0; i < a.length(); i++)
	{
		arr.push_back(a[i]-'0');
	}
	sort(arr.begin(), arr.end(), desc);

	for (int i = 0; i < a.length(); i++)
	{
		cout << arr[i];
	}
}