#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[11];

int main()
{
	int N, M;
	cin >> N >> M;

	
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		arr[x]++;
	}

	int cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		N -= arr[i];
		cnt += N * arr[i];
	}

	cout << cnt;
}