#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int arr[125][125];
int d[125][125];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		
		// 초기화 작업
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				arr[a][b] = 0;
			}
		}
		for (int a = 0; a < n; a++) {
			fill(d[a], d[a] + 125, INF);
		}
		//입력
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				cin >> arr[a][b];
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;

		d[0][0] = arr[0][0];
		pq.push({ -arr[0][0], { 0,0 } });

		while (!pq.empty()) {
			pair<int, pair<int, int>> num = pq.top();
			int cost = -num.first;
			int x = num.second.first;
			int y = num.second.second;
			pq.pop();

			if (d[x][y] < cost) {
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					continue;
				}

				if (d[nx][ny] > d[x][y] + arr[nx][ny]) {
					d[nx][ny] = d[x][y] + arr[nx][ny];
					pq.push({ -d[nx][ny],{nx,ny} });
				}

			}
		}

		for (int m = 0;m < n; m++) {
			for (int l = 0; l < n; l++) {
				cout << d[m][l] << " ";
			}
			cout << "\n";
		}

	}
}