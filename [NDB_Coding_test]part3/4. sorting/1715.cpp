#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	//우선순위 큐 : 큰 수 부터
	priority_queue<int> arr;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push(-num);
	}

	int sum = 0;

	if (N == 1)
	{
		cout << 0;
	}
	else
	{
		while (!arr.empty()) {
			int x = -arr.top();
			arr.pop();

			if (arr.empty()) {
				cout << sum;
			}
			else
			{
				int y = -arr.top();
				arr.pop();
				sum += (x + y);
				arr.push(-(x + y));
			}
		}
	}
	
}