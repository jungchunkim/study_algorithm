#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int graph[100][100][100];
queue<pair<int, pair<int, int>>> q;
int M, N, H;

int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,1,-1,0,0 };

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx<0 || ny < 0 || nz < 0 || nx>=H || ny >= N || nz >= M || graph[nx][ny][nz]!=0) {
				continue;
			}

			graph[nx][ny][nz] = graph[x][y][z] + 1;
			q.push({ nx,{ny,nz} });
		}
	}
}

int main() {
	
	cin >> M >> N >> H;



	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1) {
					q.push({ i,{j,k} });
				}
			}
		}
	}

	if (q.empty()) {
		//익은 토마토가 없으면
		cout << -1;
		return 0;
	}
	else {
		bfs();
	}

	int max_cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (graph[i][j][k] == 0) {
					cout << -1;
					return 0;
				}

				max_cnt = max(max_cnt, graph[i][j][k]);
			}
		}
	}

	if (max_cnt == 1) {
		cout << 0;
		return 0;
	}
	else {
		cout << max_cnt - 1;
	}

	
}