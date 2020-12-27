#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<vector<int>> arr(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> a(N,0);

	for (int i = 0; i < N / 2; i++)
	{
		a[i] = 1;
	}

	sort(a.begin(), a.end());


	int result=2147483647;
	do {
		vector<int> first;
		vector<int> second;

		int one = 0;
		int two = 0;

		//0Àº 1ÆÀ¿¡ 1ÀÎ 2ÆÀ¿¡ ³Ö´Â´Ù.
		for (int i = 0; i < N; i++)
		{
			if (a[i] == 1)
				second.push_back(i);
			else
				first.push_back(i);
		}

		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				one += arr[first[i]][first[j]];
				two += arr[second[i]][second[j]];
			}
		}

		int diff = one - two;
		if (diff < 0)
			diff = -diff;

		if (result > diff)
			result = diff;

	} while (next_permutation(a.begin(), a.end()));


	cout << result;
}