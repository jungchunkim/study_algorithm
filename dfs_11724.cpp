#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr[1001];
bool state[1001];
int N, M;

void dfs(int start)
{

	state[start] = 1;

	for (int i = 0; i < arr[start].size(); i++)
	{
		int k = arr[start][i];
		if (state[k] == 0)
			dfs(k);
	}
}

int main()
{
	cin >> N >> M;

	int a, b;
	// 배열에 연결 값을 넣어준다.
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int sol = 0;
	for (int i = 1; i <= N; i++)
	{
		if (state[i] == 0)
		{
			dfs(i);
			sol++;
		}
	}

	cout << sol;
}