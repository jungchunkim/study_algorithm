#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N, M;
int graph[1000][1000];

bool dfs(int x, int y)
{
	if (x <= -1 || x >= N || y <= -1 || y >= M) {
		return false;
	}
	if (graph[x][y] == 0)
	{
		graph[x][y] = 1;
		dfs(x - 1, y);
		dfs(x , y-1);
		dfs(x , y+1);
		dfs(x + 1, y);
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}

	cout << result;
}