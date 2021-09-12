#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector < pair<int, pair<int, int>>> edges;
int parent[100000];

int parent_node(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = parent_node(parent[x]);
	}
}

void union_node(int x, int y) {
	int k = parent_node(x);
	int m = parent_node(y);

	if (k > m) {
		parent[k] = m;
	}
	else {
		parent[m] = k;
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 100000; i++) {
		parent[i] = i;
	}

	vector<pair<int, int>> x;
	vector<pair<int, int>> y; 
	vector<pair<int, int>> z;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < N - 1; i++) {
		edges.push_back({ abs(x[i].first - x[i + 1].first) ,{x[i].second,x[i + 1].second} });
		edges.push_back({ abs(y[i].first - y[i + 1].first) ,{y[i].second,y[i + 1].second} });
		edges.push_back({ abs(z[i].first - z[i + 1].first) ,{z[i].second,z[i + 1].second} });
	}

	sort(edges.begin(), edges.end());


	int sum_cost = 0;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int x = edges[i].second.first;
		int y = edges[i].second.second;

		if (parent_node(x) != parent_node(y)) {
			union_node(x, y);
			sum_cost += cost;
		}
	}

	cout << sum_cost;
}