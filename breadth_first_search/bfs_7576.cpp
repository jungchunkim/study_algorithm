#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int graph[1000][1000];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int M, N;
queue<pair<int, int>> q;

void bfs() {
	
	while (!q.empty()) {
		int start_x = q.front().first;
		int start_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = start_x + dx[i];
			int ny = start_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M||graph[nx][ny]==-1) {
				continue;
			}

			if (graph[nx][ny] == 0) {
				graph[nx][ny] = graph[start_x][start_y] + 1;
				q.push({ nx,ny });
			}
			else {
				if (graph[start_x][start_y] + 1 < graph[nx][ny]) {
					graph[nx][ny] = graph[start_x][start_y] + 1;
					q.push({ nx,ny });
				}
			}
			

		}
	}

}

int main() {

	cin >> M >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	
	bfs();

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				cout << -1;
				return 0;
			}
			ans = max(ans, graph[i][j]);
		}
	}

	cout << ans - 1;
}