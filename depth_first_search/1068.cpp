#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[50];
int N;
int ans;
int delete_node;

void dfs(int x) {
	if (graph[x].empty()) {
		ans++;
		return;
	}

	bool is_in = false;
	for (int i = 0; i<graph[x].size(); i++) {
		if (graph[x][i] == delete_node) {
			//없앤 노드일때
			continue;
		}
		else {
			is_in = true;
			dfs(graph[x][i]);
		}
	}

	if (is_in == false) {
		ans++;
	}
}

int main() {
	
	cin >> N;

	int start_node;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			start_node = i;
		}
		else {
			graph[num].push_back(i);
		}
	}

	
	cin >> delete_node;

	if (delete_node == start_node) {
		cout << 0;
		return 0;
	}
	else {
		dfs(start_node);
	}
	
	cout << ans;
}