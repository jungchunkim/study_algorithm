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
		cout << 0;
		return 0;
	}

	queue<pair<int, int>> q;
	q.push(pair<int, int>(A, B));
	state[A][B] = true;

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
			sol = 1;
			break;
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
		
			vector<int> arr;
			arr.push_back(x);
			arr.push_back(y);
			arr.push_back(z);
			sort(arr.begin(), arr.end());

			if (state[arr[0]][arr[1]] == 0)
			{
				state[arr[0]][arr[1]] = true;
				cout << arr[0] << arr[1] << arr[2] << endl;
				q.push(pair<int, int>(arr[0], arr[1]));
			}
		}

	}
	cout << sol;

}