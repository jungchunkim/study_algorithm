#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// 큰 수의 법칙
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	vector<int> arr;
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	int num_1 = arr[0];
	int num_2 = arr[1];

	int num_3 = M / (K + 1);
	int num_4 = M % (K + 1);

	int sol = num_3 * (K*num_1) + num_3 * (1 * num_2) + num_4 * num_1;

	cout << sol;

}