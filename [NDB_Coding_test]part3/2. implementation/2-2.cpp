#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<char> c;

	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - '0' < 10)
		{//¼ýÀÚ¸é
			sum += s[i] - '0';
		}
		else
		{
			c.push_back(s[i]);
		}
	}

	sort(c.begin(), c.end());

	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i];
	}

	cout << sum;


}