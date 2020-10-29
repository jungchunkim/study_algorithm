#include <iostream>
#include <vector>

using namespace std;

int graph[100][100];
int temp[100][100];

int N;

void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
	{
		return;
	}
	if (temp[x][y] == 0)
		return;

	temp[x][y] = 0;
	dfs(x - 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
	dfs(x + 1, y);
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	int max = 0;
	int num = 0;

	while (1)
	{
		int sol = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] > num)
					temp[i][j] = 1;
				else
					temp[i][j] = 0;
			}
		}


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (temp[i][j] == 1)
				{
					dfs(i, j);
					sol++;
				}
			}
		}
		num++;

		if (sol == 0)
			break;

		if (sol > max)
			max = sol;
	}


	cout << max;
}