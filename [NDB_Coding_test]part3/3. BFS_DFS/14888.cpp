#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[12];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> brr;
	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			brr.push_back(i + 1);
		}
	}

	int max_num = -1000000001;
	int min_num = 1000000001;


	do {
		int sum = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (brr[i-1] == 1){
				sum = sum + arr[i];
			}
			else if (brr[i-1] == 2) {
				sum = sum - arr[i];
			}
			else if (brr[i-1] == 3) {
				sum = sum * arr[i];
			}
			else {
				sum = sum / arr[i];
			}
		}
		if (sum > max_num) {
			max_num = sum;
		}
		if (sum < min_num) {
			min_num = sum;
		}

	} while (next_permutation(brr.begin(), brr.end()));

	cout << max_num << endl << min_num;
}