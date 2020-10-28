#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int sol;
vector<int> arr[101];	// 컴퓨터 1~100 까지 있다.
bool state[101];


void dfs(int start)
{
	state[start] = true;
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
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	dfs(1);
	
	int sol = 0;
	for (int i = 1; i <= N; i++)
	{
		if (state[i] == 1)
			sol++;
	}
	cout << sol-1;

}