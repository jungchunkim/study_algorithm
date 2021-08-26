#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[8][8];
int temp_graph[8][8];
int result;

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int N, M;

void dfs(int a, int b)
{
	for (int i = 0; i < 4; i++)
	{
		int x = a + dx[i];
		int y = b + dy[i];

		if (x >= 0 && x < N && y >= 0 && y < M)
		{
			if (temp_graph[x][y] == 0)
			{
				temp_graph[x][y] = 3;
				dfs(x, y);
			}

		}
	}
}

int count_zero()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp_graph[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
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

	vector<pair<int, int>> empty_arr;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0)
			{
				empty_arr.push_back({ i,j });
			}
		}
	}

	vector<int> arr(empty_arr.size(), 0);
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;


	do {
		copy(&graph[0][0], &graph[0][0] + 64, &temp_graph[0][0]);
		
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == 1)
			{
				temp_graph[empty_arr[i].first][empty_arr[i].second] = 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp_graph[i][j] == 2)
					dfs(i, j);
			}
		}
		
		result = max(result, count_zero());
	} while (prev_permutation(arr.begin(), arr.end()));


	cout << result;
}