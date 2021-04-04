#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int graph[200][200];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> arr;
	arr.push(make_pair(x, y));

	while (!arr.empty())
	{
		int nx = arr.front().first;
		int ny = arr.front().second;
		arr.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx2 = nx + dx[i];
			int ny2 = ny + dy[i];
			if (nx2 < 0 || ny2 < 0 || nx2 >= N || ny2 >= M || graph[nx2][ny2] == 0)
			{
				continue;
			}

			if (graph[nx2][ny2] == 1)
			{//처음 간 곳
				arr.push(make_pair(nx2, ny2));
				graph[nx2][ny2] = graph[nx][ny] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	string s;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);

	cout << graph[N - 1][M - 1];
}