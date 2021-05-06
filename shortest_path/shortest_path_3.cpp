#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 

using namespace std;

int n, m;
int graph[501][501];

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < 501; i++) {
		fill(graph[i], graph[i] + 501, INF);
	}

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b) 
				graph[a][b] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	// 수행된 결과를 출력
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
			if (graph[a][b] == INF) {
				cout << "INFINITY" << ' ';
			}
			// 도달할 수 있는 경우 거리를 출력
			else {
				cout << graph[a][b] << ' ';
			}
		}
		cout << '\n';
	}
}