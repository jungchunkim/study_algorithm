#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int N, M;
	int num;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);

		cin >> num;
		// num�� arr �迭���� �̺�Ž������
		int left = 0;
		int right = N - 1;
		
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (arr[mid] == num)
			{
				cout << 1 << " ";
				break;
			}
			else if (arr[mid] < num)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if (left > right)
		{
			cout << 0 << " ";
		}
	}

}