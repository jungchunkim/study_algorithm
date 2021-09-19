#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[300001];

vector<int> d(300001, -1);

int main() {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
	}

	queue<int> q;
	q.push(X);
	d[X] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i];

			if (d[nextNode] == -1) {
				d[nextNode] = d[now] + 1;
				q.push(nextNode);
			}
		}

	}

	vector<int> result;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			result.push_back(i);
		}
	}

	if (result.empty()) {
		cout << -1;
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
}