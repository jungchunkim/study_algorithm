#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[8];

void backtracking(vector<int> &brr, int index)
{
	int x = brr.size();
	if (x == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << brr[i] << " ";
		}
		cout << endl;
		return;
	}
	

	for (int i = index; i < N; i++)
	{
		brr.push_back(arr[i]);
		backtracking(brr, i + 1);
		brr.pop_back();

	}

}

int main()
{
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		arr[i] = i+1;
	}

	vector<int> b;
	backtracking(b, 0);

}