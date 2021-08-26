#include <iostream>
#include <algorithm>

using namespace std;

int graph[501][501];
int max_graph[501][501];

int dx[] = { 1,1 };
int dy[] = { 0,1 };

int main()
{
	int N;
	cin >> N;

	// 배열 초기화
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			graph[i][j] = -1;
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> graph[i][j];
		}
	}

	max_graph[1][1] = graph[1][1];

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] == -1)
			{
				break;
			}

			for (int k = 0; k < 2; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				
				max_graph[x][y] = max(max_graph[x][y], max_graph[i][j] + graph[x][y]);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		result = max(result, max_graph[N][i]);
	}

	cout << result;

}