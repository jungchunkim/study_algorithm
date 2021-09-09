#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int arr[1001];

int main() {
	cin >> n;

	int i2 = 0, i3 = 0, i5 = 0;
	int num2 = 2;
	int num3 = 3;
	int num5 = 5;

	arr[0] = 1;
	for (int i = 1; i < n; i++) {
		arr[i] = min(num2, min(num3, num5));

		if (arr[i] == num2) {
			i2++;
			num2 = arr[i2] * 2;
		}
		if (arr[i] == num3) {
			i3++;
			num3 = arr[i3] * 3;
		}
		if (arr[i] == num5) {
			i5++;
			num5 = arr[i5] * 5;
		}
	}

	cout << arr[n - 1];
}