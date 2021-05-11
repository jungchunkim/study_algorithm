#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string arr;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int count = 0;
		cin >> arr;
		
		for (int j = 0; j < arr.length(); j++)
		{
			if (j == 0)
			{
				if (arr[j] == 'O')
				{
					count++;
				}
			}
			else
			{
				if (arr[j] == 'O')
				{
					count++;
				}
				else
				{
					count = 0;
				}
			}
	
			sum += count;
		}

		cout << sum << "\n";
	}
}