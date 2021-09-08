#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int arr[51][51];
int brr[51][51];
int N, L, R;

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

int index = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	vector<pair<int, int>> sol;

	int cnt = 0;
	int sum = 0;
	brr[x][y] = index;
	while (!q.empty()) {
		int num_x = q.front().first;
		int num_y = q.front().second;

		q.pop();
		sol.push_back({ num_x, num_y });
		

		cnt++;
		sum += arr[num_x][num_y];

		for (int i = 0; i < 4; i++) {
			int nx = num_x + dx[i];
			int ny = num_y + dy[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && brr[nx][ny] == -1) {
				int gap = abs(arr[num_x][num_y] - arr[nx][ny]);

				if (gap >= L && gap <= R) {
					q.push({ nx,ny });
					brr[nx][ny] = index;
				}

			}
		}
	}

	for (int i = 0; i < sol.size(); i++) {
		int nx = sol[i].first;
		int ny = sol[i].second;

		arr[nx][ny] = sum / cnt;
	}

}

int main() {

	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	int sol_cnt = 0;

	while (true) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				brr[i][j] = -1;
			}
		}

		index = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (brr[i][j] == -1) {
					bfs(i, j);
					index++;
				}
			}
		}

		if (index == N * N)
			break;


		sol_cnt++;
	}

	cout << sol_cnt;
}