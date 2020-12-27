#include <iostream>
#include <vector>

using namespace std;

int arr[50][50];

void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= 50 || y >= 50)
		return;
	if (arr[x][y] == 0)
		return;
	arr[x][y] = 0;
	dfs(x - 1, y);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x, y + 1);
}

int main()
{
	int T; // 테스트 케이스의 개수
	cin >> T;
	vector<int> brr;
	for (int i = 0; i < T; i++)
	{
		int M, N, K, a, b;
		int sol = 0;
		cin >> M >> N >> K;

		for (int q = 0; q < 50; q++)
		{
			for (int w = 0; w < 50; w++)
			{
				arr[q][w] = 0;
			}
		}

		// 배추가 심어저 있는 땅을 배열에 표시한다.
		for (int j = 0; j < K; j++)
		{
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int z = 0; z < M; z++)
		{
			for (int x = 0; x < N; x++)
			{
				if (arr[z][x] == 1)
				{
					dfs(z, x);
					sol++;
				}
			}
		}
		brr.push_back(sol);
	}

	for (int i = 0; i < brr.size(); i++)
		cout << brr[i] << endl;

}