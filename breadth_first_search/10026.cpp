#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

char graph[100][100];
bool visited[100][100];
int N;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int x, int y) {
	char target = graph[x][y];
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N||visited[nx][ny]==true) {
				continue;
			}
			if (graph[nx][ny] == target) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void bfs1(int x, int y) {
	char target = graph[x][y];
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == true) {
				continue;
			}

			if (target == 'G' || target == 'R') {
				if (graph[nx][ny] == 'G' || graph[nx][ny] == 'R') {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			else{
				if (graph[nx][ny] == target) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				
			}
		}
	}
}

int main() {
	cin >> N;
	
	//초기화 작업
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			graph[i][j] = s[j];
		}
	}

	int ans1 = 0;
	//적록색약이 아닌 사람
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				bfs(i, j);
				ans1++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	//적록색약인 사람
	int ans2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				ans2++;
				bfs1(i, j);
			}
		}
	}
	

	cout << ans1 << " " << ans2;


}