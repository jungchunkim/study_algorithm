#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[200][200];
int time[200][200];
int N, K;
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

vector<pair<int, int>> dist[1001];
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
				
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {

				if (time[nx][ny] == 0) {
					time[nx][ny] = time[x][y] + 1;
					graph[nx][ny] = graph[x][y];
					q.push({ nx,ny });
				}
			}
		}

	}
}

int main() {
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] != 0) {
				dist[graph[i][j]].push_back({ i,j });
				time[i][j] = 1;
			}
		}
	}

	int S, X, Y;
	cin >> S >> X >> Y;

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < dist[i].size(); j++) {
			int x = dist[i][j].first;
			int y = dist[i][j].second;
			q.push({ x,y });
		}
	}

	bfs();


	if (time[X - 1][Y - 1]<=S+1) {
		cout << graph[X - 1][Y - 1];
	}
	else {
		cout << 0;
	}
}