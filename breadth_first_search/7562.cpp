#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[300][300];

int dx[] = { -2,-2,2,2,-1,-1,1,1 };
int dy[] = { 1,-1,1,-1,-2,2,-2,2 };
int ans = 0;
int start_x, start_y;
int end_x, end_y;
int l;


void bfs(int x, int y) {
	queue < pair<int, pair<int, int>>> q;
	q.push({ 0,{x,y} });
	visited[x][y] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		int kx = q.front().second.first;
		int ky = q.front().second.second;
		
		if (kx == end_x && ky == end_y) {
			ans = cnt;
			break;
		}

		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];

			if (nx < 0 || ny < 0 || nx >= l || ny >= l || visited[nx][ny]==true) {
				continue;
			}

			q.push({ cnt + 1,{nx,ny} });
			visited[nx][ny] = true;
		}
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {

		cin >> l;
		for (int a = 0; a < 300; a++) {
			for (int j = 0; j < 300; j++) {
				visited[a][j] = false;
			}
		}

		cin >> start_x >> start_y;
		cin >> end_x >> end_y;

		ans = 0;
		bfs(start_x, start_y);

		cout << ans << "\n";
	}
}