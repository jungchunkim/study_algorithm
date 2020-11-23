#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{//중간점-1을 끝점으로 
			end = mid - 1;
		}
		else
		{//중간점 +1을 시작점으로
			start = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int n, target;
	cin >> n >> target;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int sol = binarySearch(arr, target, 0, n - 1);
	if (sol == -1)
	{
		cout<< "존재 안합니다.";
	}
	else
	{
		cout << sol + 1 << "번째 존재합니다";
	}
}