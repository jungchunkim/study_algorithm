#include <iostream>

using namespace std;

int arr[50][50];
int sol[50][50];

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int dist;

int main()
{
	int N, M;

	cin >> N >> M;
	int a, b, c;
	cin >> a >> b >> c;
	sol[a][b] = 1;
	dist = c;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int x = a;
	int y = b;
	int cnt = 0;

	int count = 1;

	while (true)
	{
		//1번째 방향을 바꿔야해
		if (dist == 3)
		{
			dist = 0;
		}
		else
		{
			dist++;
		}
		
		int x_2, y_2;
		x_2 = x + dx[dist];
		y_2 = y + dy[dist];
		cnt++;
		if (arr[x_2][y_2] == 0 && sol[x_2][y_2] == 0)
		{// 안 가본 길 이라면
			sol[x_2][y_2] = 1;
			x = x_2;
			y = y_2;
			cnt = 0;
			count++;
			continue;
		}
		else
		{//가본 길 이라면
			if (cnt == 4)
			{//4군데 다 가봤으면
				x = x - dx[dist];
				y = y - dy[dist];
				cnt = 0;
				if (arr[x][y] == 1)
				{
					break;
				}
			}
		}

	}
	cout << count;
}