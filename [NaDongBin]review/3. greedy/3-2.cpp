#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M, K;
	vector<int> arr;
	int sum = 0;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end()); // 오름차순 정렬 

	while (M > 0)
	{
		for (int i = 0; i < K; i++)
		{
			M--;
			sum += arr[N - 1];
			if (M == 0)
				break;

		}

		if (M == 0)
		{
			break;
		}
		else
		{
			sum += arr[N - 2];
			M--;
		}
	}

	cout << sum;

}