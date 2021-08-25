#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[201][201];
int time[201][201];
vector<pair<int,int>> dist[1001];

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

//S �� �Ŀ� (X,Y)�� �����ϴ� ���̷���
int S, X, Y;
// ���̷��� ��ȣ K , ����� ũ�� : N X N
int N, K;

void bfs()
{
	queue<pair<int,int>> q;

	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < dist[i].size(); j++)
		{
			int a = dist[i][j].first;
			int b = dist[i][j].second;
			q.push({ a, b });
		}
	}

	while (!q.empty())
	{
		pair<int, int> num = q.front();
		int a = num.first;
		int b = num.second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{	
			int a_num = a + dx[i];
			int b_num = b + dy[i];
			if (a_num <= N && a_num >= 1 && b_num >= 1 && b_num <= N)
			{// ����� �ȿ� ���� ��
				if (time[a_num][b_num]==0)
				{
					time[a_num][b_num] = time[a][b] + 1;
					graph[a_num][b_num] = graph[a][b];
					q.push({ a_num,b_num });
				}
			}
		}

	}


}

int main()
{
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] != 0)
			{
				dist[graph[i][j]].push_back(make_pair(i, j));
				time[i][j] = 1;
			}
		}
	}

	cin >> S >> X >> Y;

	bfs();

	if (time[X][Y] <= S+1)
	{
		cout << graph[X][Y];
	}
	else
	{
		cout << 0;
	}
}