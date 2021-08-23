#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[30001];

int d[30001];
int N, M, C;
bool visited[30001];

int findSmallnode()
{
	int small_index = INF;
	int index = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] != true && small_index > d[i])
		{
			small_index = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra()
{
	d[C] = 0;
	visited[C] = true;

	for (int i = 0; i < graph[C].size(); i++)
	{
		d[graph[C][i].first] = graph[C][i].second;
	}

	for (int i = 0; i < N - 1; i++)
	{
		//���� ��� ã��
		int index = findSmallnode();
		visited[index] = true;

		for (int j = 0;j<graph[index].size(); j++)
		{
			int cost = d[index] + graph[index][j].second;
			if (d[graph[index][j].first]>cost)
			{
				d[graph[index][j].first] = cost;
			}
		}
	}

}

int main()
{
	//C���� ���� �޽���
	cin >> N >> M >> C;
	//start �� C��� ���� �ǹ� 

	fill(d, d + 30001, INF);

	for (int i = 0; i < M; i++)
	{
		int X, Y, Z;
		cin >> X >> Y >> Z;

		graph[X].push_back({ Y,Z });
	}

	dijkstra();

	int count = 0;
	int time = 0;
	for (int i = 1; i <= N; i++)
	{
		if (d[i] != INF)
		{
			count++;
			if (time < d[i])
				time = d[i];
		}
	}

	cout << count - 1 << " " << time;
}