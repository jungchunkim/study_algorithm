#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int graph[20][20];
bool visited[26];
int R, C;
int max_ans = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void dfs(int x, int y, int count) {

	max_ans = max(max_ans, count);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C|| visited[graph[nx][ny]]==true) {
			continue;
		}
		visited[graph[nx][ny]] = true;
		dfs(nx, ny, count + 1);
		visited[graph[nx][ny]] = false;
	}
}

int main() {
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			graph[i][j] = s[j] - 'A';
		}
	}

	visited[graph[0][0]] = true;
	dfs(0, 0, 1);

	cout << max_ans;
}