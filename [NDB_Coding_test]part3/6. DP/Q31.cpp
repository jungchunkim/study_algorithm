#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { 0,-1,1 };
int dy[] = { 1,1,1 };

int main()
{
	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		int graph[21][21] = { 0 };
		int graph_max[21][21] = { 0 };

		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> graph[i][j];
			}
		}

		for (int i = 1; i <= n; i++)
		{
			graph_max[i][1] = graph[i][1];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					int x = j + dx[k];
					int y = i + dy[k];

					if (x >= 1 && x <= n)
					{
						graph_max[x][y] = max(graph_max[j][i] + graph[x][y], graph_max[x][y]);
					}
				}
			}
		}

		int result = 0;

		for (int i = 1; i <= n; i++)
		{
			result = max(result, graph_max[i][m]);
		}

		cout << result << "\n";
	}

}