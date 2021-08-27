#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph;
int max_graph[17];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int time, num;
		cin >> time >> num;
		graph.push_back({ time,num });
	}

	for (int i = 0; i < N; i++)
	{
		int x = graph[i].first;
		int y = graph[i].second;

		if ((i + 1) + x <= (N + 1))
		{
			max_graph[(i + 1 + x)] = max(max_graph[i + 1] + y, max_graph[i + 1 + x]);
			for (int j = i + 1 + x; j <= N + 1; j++)
			{
				max_graph[j] = max(max_graph[i + 1 + x], max_graph[j]);
			}
		}
	}

	cout << max_graph[N + 1];
}