#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;

int arr[100][100];
int M, N, K;
int cnt = 0;

void dfs(int x, int y) {

	if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] != 0) {
		return;
	}

	arr[x][y] = 1;
	cnt++;
	dfs(x - 1, y);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x, y + 1);

}

int main() {
	
	cin >> M >> N >> K;

	// 입력값 받기
	for (int i = 0; i < K; i++) {
		int d_x, d_y, u_x, u_y;
		cin >> d_x >> d_y >> u_x >> u_y;

	
		for (int a = d_x; a < u_x; a++) {
			for (int b = d_y; b < u_y; b++) {
				arr[a][b] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				result.push_back(cnt);
			}
		}
	}

	cout << result.size() << endl;

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}