#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	vector<string> a[51];

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		a[s.length()].push_back(s);
	}

	for (int i = 0; i < 51; i++)
	{
		if (a[i].empty() == 0)
		{
			sort(a[i].begin(), a[i].end());
		}
	}

	for (int i = 0; i < 51; i++)
	{
		if (a[i].empty() == 0)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				if (j >= 1)
				{
					if (a[i][j] == a[i][j - 1])
					{	// char �迭 ������ ���ڿ��� ���� �� strcmp()�Լ��� ����Ѵ�.
						// string ���ڿ��� ���� �� == �� compare()�Լ��� ����Ѵ�.
						continue;
					}
				}
				
				cout << a[i][j] << "\n";
			}
		}
	}
}