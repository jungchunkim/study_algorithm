#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[101];
bool visited[101];

int target_x, target_y;
int ans;

void bfs() {
	queue<pair<int,int>> q;
	q.push({ 0,target_x });
	visited[target_x] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		int target = q.front().second;

		q.pop();

		if (target == target_y) {
			ans = cnt;
			return;
		}

		for (int i = 0; i < graph[target].size(); i++) {
			if (visited[graph[target][i]] == false) {
				q.push({ cnt + 1,graph[target][i] });
				visited[graph[target][i]] = true;
			}
		}
	}
}

int main() {
	//부모와 자식 사이 1촌

	int n;
	cin >> n;

	
	cin >> target_x >> target_y;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}