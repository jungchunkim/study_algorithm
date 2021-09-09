#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	int M;
	cin >> M;

	vector<int> sol;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		
		int left_index = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
		int right_index = upper_bound(arr.begin(), arr.end(), num) - arr.begin();

		sol.push_back(right_index - left_index);
	}

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
}