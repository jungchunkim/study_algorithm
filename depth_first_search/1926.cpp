#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[500][500];
bool visited[500][500];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int num = 0;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx<0 || ny<0 || nx>=n || ny>=m) {
			continue;
		}
		if (visited[nx][ny] == true) {
			continue;
		}
		if (graph[nx][ny] == 1) {
			visited[nx][ny] = true;
			num++;
			dfs(nx, ny);
		}
		
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	int cnt = 0;
	int max_num = -1;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 1 && visited[i][j]==false) {
				num = 1;
				visited[i][j] = true;
				dfs(i, j);
				cnt++;
				max_num = max(max_num, num);
			}
		}
	}

	cout << cnt << "\n";

	if (cnt == 0) {
		cout << 0;
	}
	else {
		cout << max_num;
	}
}