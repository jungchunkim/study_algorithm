#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
int add, minu, mult, divi;

int minVal = 1e9;
int maxVal = -1e9;
int N;

void dfs(int val, int index) {
	if (index == N) {
		minVal = min(minVal, val);
		maxVal = max(maxVal, val);
	}
	else {
		if (add > 0) {
			add--;
			dfs(val + arr[index], index + 1);
			add++;
		}
		if (minu > 0) {
			minu--;
			dfs(val - arr[index], index + 1);
			minu++;
		}
		if (mult > 0) {
			mult--;
			dfs(val * arr[index], index + 1);
			mult++;
		}
		if (divi > 0) {
			divi--;
			dfs(val / arr[index], index + 1);
			divi++;
		}
	}
}

int main() {
	
	cin >> N;

	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	cin >> add >> minu >> mult >> divi;

	dfs(arr[0], 1);

	cout << maxVal << endl << minVal;
}