#include <iostream>

using namespace std;

int parent[100001];

int find_parent(int m)
{
	if (m == parent[m])
	{
		return m;
	}
	else
	{
		return parent[m] = find_parent(parent[m]);
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

	// 부모 초기값 넣어줌
	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}


	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0)
		{//a=0일때
			Union_node(b, c);
		}
		else
		{//a=1일때
			if (find_parent(b) == find_parent(c))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}

			
	}



}