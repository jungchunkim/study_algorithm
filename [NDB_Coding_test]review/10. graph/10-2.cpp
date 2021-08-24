#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> arr;
int parent[100001];
vector<int> result;

int node_parent(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = node_parent(parent[x]);
}

void Union_node(int x, int y)
{
	x = node_parent(x);
	y = node_parent(y);
	if (x > y)
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		//비용순으로 오름차순
		arr.push_back({ c, { a,b } });
	}
	
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	sort(arr.begin(), arr.end());


	
	for (int i = 0; i < M; i++)
	{
		int a = node_parent(arr[i].second.first);
		int b = node_parent(arr[i].second.second);
		if (a != b)
		{
			Union_node(a, b);
			result.push_back(arr[i].first);
		}
	}

	int sum = 0;

	for (int i = 0; i < result.size() - 1; i++)
	{
		sum += result[i];
	}

	cout << sum;
}