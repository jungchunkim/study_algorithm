#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[300][300];
int temp[300][300];
bool visited[300][300];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (graph[nx][ny] == 0) {
			if (temp[x][y] > 0) {
				temp[x][y]--;
			}
		}
	}


	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M || graph[nx][ny] == 0) {
			continue;
		}

		if (visited[nx][ny] == false) {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
		
	}
}

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	int ans = 0;
	while (true) {
		bool is_out = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
		// temp¿¡ °ª ³Ö¾îÁÜ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = graph[i][j];
			}
		}

		
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] != 0) {
					dfs(i, j);
					is_out = true;
					break;
				}
			}
			if (is_out == true) {
				break;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] = temp[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == false && graph[i][j] > 0) {
					cout << ans;
					return 0;
				}
			
			}
		}
		ans++;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum += graph[i][j];
			}
		}
		if (sum == 0) {
			cout << 0;
			return 0;
		}
	}
	
}