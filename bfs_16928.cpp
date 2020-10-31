#include <iostream>
#include <queue>

using namespace std;

int arr[101];
int dist[101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 101; i++)
	{
		arr[i] = i;
		dist[i] = -1;
	}
	
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a] = b;
	}

	queue<int> q;
	q.push(1);

	dist[1] = 0;

	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int y = k + i;

			if (y > 100)
				break;
			y = arr[y];
			// 뱀일 경우 거른다.
			if (dist[y] == -1)
			{
				dist[y] = dist[k] + 1;
				q.push(y);
			}
			
		}
	}

	cout << dist[100];
}