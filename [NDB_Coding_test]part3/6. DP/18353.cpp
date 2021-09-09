#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int brr[20000];

int main() {
	int N;
	cin >> N;
	
	vector<int> arr;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	
	for (int i = 0; i < N; i++) {
		brr[i] = 1;
	}

	int max_num = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				brr[i] = max(brr[i], brr[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		max_num = max(brr[i], max_num);
	}
	cout << N - max_num;
}