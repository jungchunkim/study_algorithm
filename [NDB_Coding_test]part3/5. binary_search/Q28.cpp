#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int result = -1;

void binarySearch(int start, int end)
{

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == mid)
		{
			result = mid;
			return;
		}
		else if (arr[mid] < mid)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}

int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		arr.push_back(num);
	}

	binarySearch(0, N - 1);

	cout << result;
}