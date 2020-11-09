#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int graph[100][100];
int dx[] = { 0,1,-1,0 };
int dy[] = { -1,0,0,1 };


int main()
{
	int N, M;
	string s;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		pair<int, int> p;
		p = q.front();
		q.pop();

		int a = p.first;
		int b = p.second;
		for (int i = 0; i < 4; i++)
		{
			int x = a + dx[i];
			int y = b + dy[i];

			if (x < 0 || y < 0 || y >= M || x >= N)
				continue;
			if (graph[x][y] == 0 || graph[x][y] != 1)
				continue;

			graph[x][y] = graph[a][b] + 1;
			q.push(make_pair(x, y));
		}

	}
	cout << graph[N - 1][M - 1];

}