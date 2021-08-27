#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int graph[101][101];

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;
		}
	}


	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (graph[a][b] < c)
		{
			continue;
		}
		else
		{
			graph[a][b] = c;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		graph[i][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << graph[i][j] << " ";
			}
		}
		cout << "\n";
	}


}