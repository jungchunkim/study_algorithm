#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//강의 시간
int time[501];
vector<int> graph[501];
int indegree[501];
int N;
int result[501];


void topology_sort()
{
	
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		result[i] = time[i];
	}

	while (!q.empty())
	{
		int index = q.front();
		q.pop();


		for (int i = 0; i < graph[index].size(); i++)
		{
			//연결돼있는 진입차수 낮춤
			indegree[graph[index][i]]--;

			result[graph[index][i]] = max(result[index] + time[graph[index][i]], result[graph[index][i]]);

			if (indegree[graph[index][i]] == 0)
			{
				q.push(graph[index][i]);
			}
		}
	}
}

int main()
{
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a = 0;
		// 처음에는 시간 입력 받음
		cin >> a;
		time[i] = a;

		while (true)
		{
			cin >> a;
			if (a == -1)
			{
				break;
			}
			else
			{
				//연결관계 표현
				graph[a].push_back(i);
				// 있을 때마다 진입차수 증가
				indegree[i]++;
			}
		}

	}

	topology_sort();


	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << endl;
	}
}