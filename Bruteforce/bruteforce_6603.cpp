#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;
		vector<int> arr(N);

		vector<int> a(N);
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < 6; i++)
		{
			a[i] = 1;
		}

		do {
			for (int i = 0; i < N; i++)
			{
				if (a[i] == 1)
					cout << arr[i] << " ";
			}

			cout << endl;
		} while (prev_permutation(a.begin(), a.end()));


	}
}