#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol = 0;

void recursive(vector<int> &a, int b, int c) {

	if (b == 0)
		return;
	int k = a.size();
	vector<int> brr(k,0);
	int sum;

	for (int i = 0; i < b; i++)
	{
		brr[i] = 1;
	}
	

	do {
		sum = 0;
		for (int i = 0; i < k; i++)
		{
			if (brr[i] == 1)
				sum += a[i];
		}

		if (sum == c)
			sol++;

	}while(prev_permutation(brr.begin(),brr.end()));

	recursive(a, b - 1, c);

}

int main()
{
	int N, S;
	cin >> N >> S;
	vector<int> arr(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	recursive(arr, N, S);
	
	cout << sol;
}