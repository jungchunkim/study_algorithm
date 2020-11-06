#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool state[1501][1501];
int sum;

// 3개의 수의 합이 일정하다는 것을 생각 안했어.
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	sum = A + B + C;
	if (sum % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int k[3] = { A,B,C };
	sort(k, k + 3);

	queue<pair<int, int>> q;
	q.push(pair<int, int>(k[0], k[1]));
	state[k[0]][k[1]] = true;

	int sol = 0;


	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		int a = temp.first;
		int b = temp.second;
		int c = sum - a - b;

		if (a == b && b == c)
		{
			cout << 1;
			return 0;
		}

		for (int i = 0; i < 3; i++)
		{
			int x, y, z;
			if (i == 0)
			{
				if (a == b)
					continue;
				x = a + a;
				y = b - a;
				z = sum - x - y;
			}
			else if (i == 1)
			{
				if (b == c)
					continue;
				x = a;
				y = b + b;
				z = sum - x - y;
			}
			else
			{
				if (a == c)
					continue;
				x = a + a;
				y = b;
				z = sum - x - y;
			}

			int arr[3] = { x,y,z };
			sort(arr, arr + 3);

			if (state[arr[0]][arr[1]] == 0)
			{
				cout << arr[0] << arr[1] << endl;
				state[arr[0]][arr[1]] = true;
				q.push(pair<int, int>(arr[0], arr[1]));
			}
		}

	}
	cout << 0;

}