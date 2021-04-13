#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == target)
			return mid;

		else if (arr[mid] > target)
			end = mid - 1;

		else start = mid + 1;
	}
	return -1;
}

int main()
{
	int N;
	vector<int> arr;
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
		int result = binarySearch(arr, num, 0, N - 1);
		if (result!=-1)
		{//부품이 있다면
			cout << "yes ";
		}
		else
		{//부품이 없다면
			cout << "no ";
		}

	}
}