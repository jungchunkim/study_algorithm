#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int arr[200][200];
int d[200][200];
int N, M;
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };


void dfs(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (x >= 0 && y >= 0 && (x < N) && (y < M))
		{
			if (arr[x][y] == 1)
			{
				if (d[x][y] == 0)
				{
					d[x][y] = d[i][j] + 1;
					dfs(x, y);
				}
				else
				{
					if (d[i][j] + 1 < d[x][y])
					{
						d[x][y] = d[i][j] + 1;
						dfs(x, y);
					}
				}
			}
		}
	}
}

int main()
{
	int count = 0;
	cin >> N >> M;
	
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	d[0][0] = 1;
	dfs(0, 0);

	cout << d[N - 1][M - 1];
	
}