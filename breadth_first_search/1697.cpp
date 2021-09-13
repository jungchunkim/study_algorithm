#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int arr[100001];

int main() {
	int N, K;
	cin >> N >> K;
	queue<pair<int, int>> q;
	q.push({ N,0 });

	while (true) {
		// 큐 는 front, 우선순위 큐는 top
		int time = q.front().second;
		int node_num = q.front().first;
		q.pop();

		if (node_num >= MAX || node_num<0 || arr[node_num] == 1)
		{
			continue;
		}

		if (node_num == K) {
			cout << time;
			break;
		}
		arr[node_num] = 1;
		q.push({ node_num - 1, time + 1 });
		q.push({ node_num + 1, time + 1 });
		q.push({ 2 * node_num , time + 1 });
	}

}