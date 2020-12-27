#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8][8];
int temp[8][8];
int N, M;

void init_()
{
	//temp에다가 값을 넣어줌.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
}

void bfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
		return;
	if (temp[x][y] == 1 || temp[x][y] == 2)
		return;

	temp[x][y] = 2;
	bfs(x - 1, y);
	bfs(x, y - 1);
	bfs(x + 1, y);
	bfs(x, y + 1);

}

int main()
{

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	// 값 중에 0 인것 vector 에 넣기
	vector<pair<int, int>> r;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				r.push_back(pair<int, int>(i, j));
		}
	}

	// 벽을 세울 배열 p 설정
	vector<int> p(r.size(), 0);
	
	p[0] = 1;
	p[1] = 1;
	p[2] = 1;

	int max = 0;
	int sol;

	do {
		init_();
		sol = 0;
		for (int i = 0; i < r.size(); i++)
		{
			if (p[i])
			{
				temp[r[i].first][r[i].second] = 1;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp[i][j] == 2) 
				{
					temp[i][j] = 0;
					bfs(i, j);
				}
					
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp[i][j] == 0)
					sol++;
			}

		}
		if (max < sol)
			max = sol;
	} while (prev_permutation(p.begin(), p.end()));

	cout << max;
}