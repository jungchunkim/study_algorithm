#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[10001];

int main() {
	int N;
	cin >> N;

	int temp = 0;

	for (int i = 0; i < N; i++) 
	{
		cin >> temp;
		cnt[temp] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] > 0) 
		{
			for (int j = 0; j < cnt[i]; j++) 
			{
				cout << i << "\n";
			}
		}
	}

	return 0;
}