#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//���� �ð�
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
			//������ִ� �������� ����
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
		// ó������ �ð� �Է� ����
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
				//������� ǥ��
				graph[a].push_back(i);
				// ���� ������ �������� ����
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