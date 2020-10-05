#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> &arr, vector<char> &brr)
{
	for (int i = 0; i < brr.size(); i++)
	{
		if (brr[i] == '<'&&arr[i] > arr[i + 1])
			return false;
		if (brr[i] == '>'&&arr[i] < arr[i + 1])
			return false;
	}	
	return true;
}

//순열을 이용한 브루트포스
int main()
{
	int N;
	cin >> N;
	vector <char> a(N);

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	vector<int> big(N + 1);
	vector<int> small(N + 1);

	for (int i = 0; i <= N; i++)
	{
		big[i] = 9 - i;
		small[i] = i;
	}

	do {
		if (check(small, a))
			break;
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(big, a))
			break;
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < big.size(); i++)
	{
		cout << big[i];
	}
	cout << endl;
	for (int i = 0; i < small.size(); i++)
	{
		cout << small[i];
	}
}