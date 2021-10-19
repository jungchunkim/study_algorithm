#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[10001];
int max_graph[10001];
bool visited[10001];

int N, M;
int ans;

// 순환도  신경써야지!
void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		ans++;
		
		for (int i = 0; i < graph[k].size(); i++) {
			if (visited[graph[k][i]] == false) {
				q.push(graph[k][i]);
				visited[graph[k][i]] = true;
			}
			
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	int max_ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = 0;
		for (int l = 1; l<=N; l++) {
			visited[l] = false;
		}
		bfs(i);
		max_graph[i] = ans;
		max_ans = max(ans, max_ans);

	}

	for (int i = 1; i <= N; i++) {
		if (max_ans == max_graph[i]) {
			cout << i << " ";
		}
	}
}