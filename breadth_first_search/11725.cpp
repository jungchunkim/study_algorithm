#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<int> graph[100001];
bool visited[100001];

int parent[100001];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int front_num = q.front();

		q.pop();
		for (int i = 0; i < graph[front_num].size(); i++) {
			if (visited[graph[front_num][i]] == false) {
				q.push(graph[front_num][i]);
				visited[graph[front_num][i]] = true;
				parent[graph[front_num][i]] = front_num;
			}
		}
	}
}

int main() {

	int N; 
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}