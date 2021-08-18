#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

void binarySearch(int num,int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == num)
		{
			cout << "yes ";
			break;
		}
		else if (arr[mid] < num)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	if (start > end)
	{
		cout << "no ";
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		binarySearch(num,0,N-1);
	}

}