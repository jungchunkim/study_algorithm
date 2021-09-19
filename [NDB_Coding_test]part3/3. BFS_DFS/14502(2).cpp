#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[8][8];
int temp[8][8];
vector<pair<int, int>> empty_graph;

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int N, M;

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				dfs(nx, ny);

			}
		}
	}

}


int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) {
				empty_graph.push_back({ i,j });
			}
		}
	}

	vector<int> arr(empty_graph.size(), 0);
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	int max_cnt = 0;
	do {
		//temp 배열 초기화
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				temp[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 1) {
				temp[empty_graph[i].first][empty_graph[i].second] = 1;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 2) {
					dfs(i, j);
				}
			}
		}
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 0) {
					cnt++;
				}
			}
		}

		max_cnt = max(max_cnt, cnt);

	} while (prev_permutation(arr.begin(), arr.end()));

	cout << max_cnt;

}