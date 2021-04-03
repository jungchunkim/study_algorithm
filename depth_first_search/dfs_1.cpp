#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


int N, M;
vector<int> arr[100];

void dfs(int a, int b)
{
	if (a <= -1 || b <= -1 || a >= N || b >= M)
	{
		return;
	}
	if (arr[a][b] == 0)
	{
		arr[a][b] = 1;
		dfs(a + 1, b);
		dfs(a, b - 1);
		dfs(a - 1, b);
		dfs(a, b + 1);
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
			arr[i].push_back(s[j] - '0');
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				continue;
			}
			else
			{
				count++;
				dfs(i, j);

			}
		}
	}

	cout << count;
}