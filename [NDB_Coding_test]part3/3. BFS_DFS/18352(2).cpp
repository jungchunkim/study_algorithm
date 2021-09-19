#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> graph[300001];
int dist[300001];

void dijkstra(int start) {
	dist[start] = 0;

	priority_queue<pair<int, int>> q;

	q.push({ 0,start });

	while (!q.empty()) {
		int x = -q.top().first;
		int y = q.top().second;
		q.pop();

		if (dist[y] < x) {
			continue;
		}

		for (int i = 0; i < graph[y].size(); i++) {
			int cost = graph[y][i].second + dist[y];

			if (cost < dist[graph[y][i].first]) {
				dist[graph[y][i].first] = cost;
				q.push({ -cost, graph[y][i].first });
			}
		}

	}

}


int main() {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back({ b,1 });
	}

	dijkstra(X);

	vector<int> result;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
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