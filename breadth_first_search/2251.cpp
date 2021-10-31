#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[201][201][201];
vector<int> ans;
int a, b, c;
queue<pair<int, pair<int, int>>> q;

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();

		if (visited[x][y][z] == true) {
			continue;
		}

		visited[x][y][z] = true;
		if (x == 0) {
			ans.push_back(z);
		}
		

		//a->b
		if (x + y > b) {
			q.push({ x - (b - y),{b,z} });
		}
		else {
			q.push({ 0,{(x + y),z} });
		}
		//a->c
		if (x + z > c) {
			q.push({ x - (c - z),{y,c} });
		}
		else {
			q.push({ 0,{y,(x + z)} });
		}
		//c->a
		if (x + z > a) {
			q.push({ a,{y,z - (a - x)} });
		}
		else {
			q.push({ x + z,{y,0} });
		}

		//c->b
		if (y + z > b) {
			q.push({ x,{b,z - (b - y)} });
		}
		else {
			q.push({ x ,{y + z,0} });
		}
		//b->c
		if (y + z > c) {
			q.push({ x ,{y - (c - z),c} });
		}
		else {
			q.push({ x ,{0,y + z} });
		}

		//b->a
		if (x + y > a) {
			q.push({a ,{y-(a-x),z} });
		}
		else {
			q.push({ x + y,{0,z} });
		}
	}

}

int main() {

	cin >> a >> b >> c;
	q.push({ 0,{0,c} });
	bfs();
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}