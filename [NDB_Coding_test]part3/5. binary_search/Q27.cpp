#include <iostream>
#include <vector>

using namespace std;

int N, x;
vector<int> arr;
int index;

void binary_search(int start, int end)
{
	int mid = (start + end) / 2;

	if (start > end)
	{
		index = -1;
		return;
	}

	if (arr[mid] == x)
	{
		index = mid;
	}
	else if (arr[mid] > x)
	{
		binary_search(start, mid - 1);
	}
	else
	{
		binary_search(mid + 1, end);
	}

}

int main()
{
	
	cin >> N >> x;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	binary_search(0, N - 1);
	if (index == -1)
	{
		cout << -1;
	}
	else
	{
		while (true)
		{
			if (arr[index] == x)
			{
				index--;
			}
			else
			{
				index++;
				break;
			}
		}

		int cnt = 0;
		while (arr[index] == x)
		{
			cnt++;
			index++;
		}

		cout << cnt;

	}
	
}