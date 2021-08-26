#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	int index = (N / 2) - 1;

	int result = 0;
	while (true)
	{
		int distance = 0;

		for (int i = 0; i < N; i++)
		{
			distance += (arr[index] - arr[i]);
		}

		if (result == 0)
		{
			result = distance;
		}
		else
		{
			if (result < distance)
			{// distance 가 더 클 떄
				break;
			}
			else
			{// distance가 더 작을 때 
				result = distance;
			}
		}
		index++;
	}

	cout << arr[index - 1];
}