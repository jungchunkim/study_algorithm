#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, C;

	cin >> N >> C;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	int first = 1;
	int end = arr[N - 1] - arr[0];
	int result = 0;

	while (first <= end) {
		int mid = (first + end) / 2;

		int cnt = 1;
		int prev_num = arr[0];

		for (int i = 1; i < N; i++) {
			if (arr[i] - prev_num >= mid) {
				cnt++;
				prev_num = arr[i];
			}
		}

		if (cnt >= C) {
			first = mid + 1;
			result = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}