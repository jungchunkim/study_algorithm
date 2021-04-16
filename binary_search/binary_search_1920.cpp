#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

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
		bool is_true = false;
		int start = 0;
		int end = N - 1;
		int mid;
		while (start<=end)
		{
			mid = (start + end) / 2;

			if (arr[mid] > num)
			{
				end = mid - 1;
			}
			else if(arr[mid]<num)
			{
				start = mid + 1;
			}
			else
			{
				is_true = true;
				cout << "1" << "\n";
				break;
			}
		}
		if (is_true == false)
		{
			cout << "0" << "\n";
		}


	}
}