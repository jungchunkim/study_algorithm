#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> arr;
int parent[200000];

int parent_node(int k) {
	if (k == parent[k]) {
		return k;
	}
	else {
		return parent[k] = parent_node(parent[k]);
	}
		
}

void union_node(int a, int b) {
	int x = parent_node(a);
	int y = parent_node(b);

	if (x > y) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int first_cost = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		first_cost += c;
		arr.push_back({ c,{a,b} });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < arr.size(); i++) {
		int cost = arr[i].first;
		int x = arr[i].second.first;
		int y = arr[i].second.second;

		if (parent_node(x) == parent_node(y)) {
			// 순환을 만들때
			continue;
		}
		else {
			union_node(x, y);
			first_cost -= cost;
		}
	}


	cout << first_cost;
}