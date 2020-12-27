#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000


using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector <int> oper(4);
	
	// 차례대로 + - * / 의 개수
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	vector <int> real;

	for (int i = 0; i < N - 1; i++)
	{
		if (oper[0] != 0)
		{
			real.push_back(0);
			oper[0]--;
		}
		else if (oper[1] != 0)
		{
			real.push_back(1);
			oper[1]--;
		}
		else if (oper[2] != 0)
		{
			real.push_back(2);
			oper[2]--;
		}
		else
		{
			real.push_back(3);
			oper[3]--;
		}
	}
	
	sort(real.begin(), real.end());
	


	int sum;
	//초기값을 넣어준다.
	int max = MIN;
	int min = MAX;

	do {
		sum = arr[0];
		for (int i = 0; i < N - 1; i++)
		{
			if (real[i] == 0)
			{
				sum = sum + arr[i + 1];
			}
			else if (real[i] == 1)
			{
				sum = sum - arr[i + 1];
			}
			else if (real[i] == 2)
			{
				sum = sum * arr[i + 1];
			}
			else
			{
				sum = sum / arr[i + 1];
			}
		}
		if (sum > max)
		{
			max = sum;
		}
		if (sum < min)
		{
			min = sum;
		}

	} while (next_permutation(real.begin(), real.end()));

	cout << max << endl << min;
}