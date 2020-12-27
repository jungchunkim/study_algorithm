#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
bool state[1000];
bool state_1[1000];
vector<int> arr[1001];

void dfs(int start)
{
	state[start] = 1;
	cout << start << " ";
	for (int i = 0; i < arr[start].size(); i++)
	{
		int k = arr[start][i];
		if (state[k] == 0)
		{		
			dfs(k);
		}
	}
	
}

void bfs(int start)
{
	state_1[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int k = q.front();
		cout << k << " ";
		q.pop();
		for (int i = 0; i < arr[k].size(); i++)
		{
			if (state_1[arr[k][i]] == 0)
			{
				q.push(arr[k][i]);
				state_1[arr[k][i]] = 1;
			}
		}

	}
}



int main()
{

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	dfs(V);
	cout << endl;

	bfs(V);
}