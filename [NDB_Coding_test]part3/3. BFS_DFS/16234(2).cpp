#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, L, R;
int arr[50][50];
int temp[50][50];

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int num_index = 1;
int sum_num;
int cnt_num;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || temp[nx][ny] != 0) {
				continue;
			}

			if (abs(arr[nx][ny] - arr[kx][ky]) >= L && abs(arr[nx][ny] - arr[kx][ky]) <= R) {
				q.push({ nx, ny });
				temp[nx][ny] = num_index;
				cnt_num++;
				sum_num += arr[nx][ny];
			}
		}
	}
}

int main() {
	
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int solu = 0;
	while (true) {

		bool ret = true;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = 0;
			}
		}

	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp[i][j] == 0) {
					sum_num = 0;
					cnt_num = 0;

					bfs(i, j);

					if (cnt_num > 0) {
						ret = false;
						temp[i][j] = num_index;
						for (int a = 0; a < N; a++) {
							for (int b = 0; b < N; b++) {
								if (temp[a][b] == num_index) {
									arr[a][b] = (sum_num) / (cnt_num);
								}
							}
						}
						num_index++;
					}
				}
			}
		}
		if (ret == true) {
			break;
		}
		else {
			solu++;
		}
	}

	
	cout << solu;
}