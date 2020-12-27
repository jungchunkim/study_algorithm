#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[200][200];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = -1;
		}
	}

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int ds1[] = { 2,2,0,-2,-2,0 };
	int ds2[] = { 1,-1,-2,-1,1,2 };

	queue<pair<int, int>> q;
	q.push(pair<int, int>(r1, c1));
	dist[r1][c1] = 0;
	while (!q.empty())
	{
		pair<int, int> r = q.front();
		q.pop();
		int x = r.first;
		int y = r.second;

		for (int i = 0; i < 6; i++)
		{
			int a = x + ds1[i];
			int b = y + ds2[i];
			//범위를 벗어날 경우
			if (a < 0 || b < 0 || a >= n || b >= n)
			{
				continue;
			}

			if (dist[a][b] == -1)
			{
				dist[a][b] = dist[x][y] + 1;
				q.push(pair<int, int>(a, b));
			}
		}

	}

	cout << dist[r2][c2];
}