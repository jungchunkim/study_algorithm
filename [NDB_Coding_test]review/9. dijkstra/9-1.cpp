#include <iostream>
#define INF 1e9
#include <algorithm>

using namespace std;

int graph[101][101];

int main()
{
	int N, M;
	cin >> N >> M;

	// 무한대로 초기화
	for (int i = 0; i < 101; i++)
	{
		fill(graph[i], graph[i] + 101, INF);
	}


	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		graph[i][i] = 0;
	}

	int X, K;
	cin >> X >> K;


	for (int i = 1; i <= N; i++)
	{
		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
			}
		}
	}

	// 가는 경로 최소 이동 시간
	int result = graph[1][K] + graph[K][X];
	if (result >= INF)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
}