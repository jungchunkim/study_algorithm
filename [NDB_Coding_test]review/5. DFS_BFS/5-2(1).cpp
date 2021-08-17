#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int arr[200][200];
int N, M;
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };


void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		pair<int, int> num=q.front();
		q.pop();
		int x = num.first;
		int y = num.second;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && (nx < N) && (ny < M))
			{
				if (arr[nx][ny] == 1)
				{
					arr[nx][ny] = arr[x][y] + 1;
					q.push({ nx,ny });
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

	bfs(0, 0);

	cout << arr[N - 1][M - 1];
	
}