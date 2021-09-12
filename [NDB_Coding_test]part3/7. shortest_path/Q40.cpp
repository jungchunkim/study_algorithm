#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> arr[20001];
int dist[20001];

void dijkstra(int start) {
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < cost) {
			continue;
		}

		for (int i = 0; i < arr[node].size(); i++) {
			int x = arr[node][i].first;
			int y = arr[node][i].second;

			if (dist[x] > dist[node] + y) {
				dist[x] = dist[node] + y;
				pq.push({ -dist[x],x });
			}
		}

	}


}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		arr[x].push_back({ y,1 });
		arr[y].push_back({ x,1 });
	}

	fill(dist, dist + 20001, INF);
	
	dijkstra(0);


	int max_num = 0;
	int max_dist = 0;
	int sum_node = 0;

	
	
	for (int i = 1; i <= N; i++) {
		if (dist[i] == 1e9) {
			continue;
		}

		if (dist[i] > max_dist) {
			max_dist = dist[i];
			max_num = i;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (max_dist == dist[i]) {
			sum_node++;
		}
	}
	

	cout << max_num << " " << max_dist << " " << sum_node;
	
}