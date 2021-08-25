#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<int> arr[300001];
int dist[300001];
int N, M, K, X;

void bfs()
{
	queue<int> q;
	q.push(X);

	while (!q.empty())
	{
		int start = q.front();
		q.pop();

		if (arr[start].empty() || dist[start] >= K)
			continue;

		for (int i = 0; i < arr[start].size(); i++)
		{
			int num = arr[start][i];
			if (dist[num] > dist[start] + 1)
			{
				q.push(num);
				dist[num] = dist[start] + 1;
			}
			
		}
	}
}

int main()
{
	
	cin >> N >> M >> K >> X;
	
	
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		
	}
	dist[X] = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}

	bfs();

	
	vector<int> ans;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
			ans.push_back(i);
	}

	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}

	
}