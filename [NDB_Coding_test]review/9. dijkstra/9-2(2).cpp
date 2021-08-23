#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[30001];

int d[30001];
int N, M, C;

void dijkstra()
{
	priority_queue<pair<int, int>> pq;
	
	pq.push({ 0,C });
	d[C] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;	// 현재 거리
		int now = pq.top().second;	// 현재 노드
		pq.pop();

		//이미 처리된 적이 있는 노드
		if (d[now] < dist)
			continue;
		
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main()
{
	//C에서 보낸 메시지
	cin >> N >> M >> C;
	//start 가 C라는 것을 의미 

	fill(d, d + 30001, INF);

	for (int i = 0; i < M; i++)
	{
		int X, Y, Z;
		cin >> X >> Y >> Z;

		graph[X].push_back({ Y,Z });
	}

	dijkstra();

	int count = 0;
	int time = 0;
	for (int i = 1; i <= N; i++)
	{
		if (d[i] != INF)
		{
			count++;
			if (time < d[i])
				time = d[i];
		}
	}

	cout << count - 1 << " " << time;
}