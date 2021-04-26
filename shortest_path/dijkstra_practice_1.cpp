#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9 

using namespace std;


int n, m, start;
vector<pair<int, int> > graph[100001];
bool visited[100001];
int d[100001];


int getSmallestNode() {
	int min_value = INF;
	int index = 0; 
	for (int i = 1; i <= n; i++) 
	{
		// 정해진 적 없는 노드 중 가장 값이 작은 value 찾는다.
		if (d[i] < min_value && !visited[i]) 
		{
			min_value = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	d[start] = 0;
	visited[start] = true;
	// 처음 노드에 대한 가까운 노드 거리 배열에 넣는다.
	for (int j = 0; j < graph[start].size(); j++) 
	{
		d[graph[start][j].first] = graph[start][j].second;
	}

	for (int i = 0; i < n - 1; i++) 
	{
		int now = getSmallestNode();
		//다음으로 값이 작은 노드
		visited[now] = true;
		
		for (int j = 0; j < graph[now].size(); j++) 
		{
			int cost = d[now] + graph[now][j].second;
			
			if (cost < d[graph[now][j].first]) {
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	fill_n(d, 100001, INF);
	
	dijkstra(start);

	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) {
			cout << "INFINITY" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}
}