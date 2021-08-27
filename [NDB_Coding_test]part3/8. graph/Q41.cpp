#include <iostream>
#include <vector>

using namespace std;

int graph[501][501];
int parent[501];

int find_parent(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	else
	{
		return parent[x] = find_parent(parent[x]);
	}
}

void Union_node(int x, int y)
{
	int x_num = find_parent(x);
	int y_num = find_parent(y);

	if (x_num > y_num)
	{
		parent[x_num] = y_num;
	}
	else
	{
		parent[y_num] = x_num;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j] == 1)
			{
				if (find_parent(i) != find_parent(j))
				{
					Union_node(i, j);
				}
			}
		}
	}

	
	vector<int> arr;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		arr.push_back(num);
	}

	bool num_true = true;
	for (int i = 0; i < M-1; i++)
	{
		if (find_parent(arr[i]) != find_parent(arr[i + 1]))
		{
			num_true = false;
		}
	}

	if (num_true)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

}