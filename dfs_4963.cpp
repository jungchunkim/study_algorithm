#include <iostream>
#include <vector>

using namespace std;

int graph[51][51];
int w, h;

void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x>=h || y>=w)
		return;
	if (graph[x][y] == 0)
		return;

	graph[x][y] = 0;
	dfs(x - 1, y);
	dfs(x - 1, y + 1);
	dfs(x - 1, y - 1);
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x + 1, y - 1);
	dfs(x + 1, y + 1);

}

int main()
{
	while (1)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		//  graph에 입력 값을 넣는다.
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> graph[i][j];
			}
		}

		int sol = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (graph[i][j] == 1)
				{
					dfs(i, j);
					sol++;
				}
			}
		}

		for (int i = 0; i < 51; i++)
			for (int j = 0; j < 51; j++)
				graph[i][j] = 0;

		cout << sol << endl;
	}

}