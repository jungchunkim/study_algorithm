#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9


using namespace std;

int graph[501][501];

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		graph[i][i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] == INF)
				graph[i][j] = -1;
		}
	}

	
	for (int i = 1; i <= N; i++)
	{
		bool ans_true = true;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			if (graph[i][j] < 0 && graph[j][i] < 0)
			{
				ans_true = false;
				break;
			}
		}
		if (ans_true == true)
			cnt++;
	}

	cout << cnt;
}