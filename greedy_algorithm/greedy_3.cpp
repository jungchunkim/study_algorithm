#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> arr[100];

	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			arr[i].push_back(num);
		}
		sort(arr[i].begin(), arr[i].end());
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < arr[i][0])
		{
			max = arr[i][0];
		}
	}

	cout << max;
}