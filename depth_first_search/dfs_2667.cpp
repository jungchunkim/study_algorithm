#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

bool state[25][25];
int N;
int a;

void recursion(int i, int j)
{
	if (state[i][j] == 0)
		return;
	if (i < 0 || j < 0 || i >= N || j >= N)
	{
		return;
	}
	state[i][j] = 0;
	a++;
	recursion(i - 1, j);
	recursion(i, j - 1);
	recursion(i + 1, j);
	recursion(i, j + 1);
}

int main()
{

	cin >> N;
	int sol = 0;
	vector<int> arr;
	string h;

	for (int i = 0; i < N; i++)
	{
		cin >> h;
		for (int j = 0; j < N; j++)
		{
			if (h[j] == '1')
				state[i][j] = 1;
			else
				state[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (state[i][j] == 1)
			{
				sol++;
				a = 0;
				recursion(i,j);
				arr.push_back(a);
			}
		}
	}

	cout << sol;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < sol; i++)
		cout << endl << arr[i];
}