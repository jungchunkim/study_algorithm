#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 1) {
			continue;
		}
		else {
			bool is_true = true;
			for (int j = 2; j <= sqrt(num); j++) {
				if (num%j == 0) {
					is_true = false;
					break;
				}
			}
			if (is_true) {
				cnt++;
			}
		}
	}

	cout << cnt;
}