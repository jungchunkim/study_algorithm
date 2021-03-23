#include <iostream>
#include <deque>

using namespace std;

int main()
{

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	deque<pair<int, int>> arr;

	int num;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		arr.push_back(make_pair(num,i));
	}

	int move_num;
	while (1)
	{
		move_num = arr.front().first;
		cout << arr.front().second << " ";
		arr.pop_front();

		if (arr.empty())
		{
			break;
		}
		if (move_num > 0)
		{//오른쪽으로 이동 
			for (int i = 1; i < move_num; i++)
			{
				arr.push_back(arr.front());
				arr.pop_front();
			}

		}
		else
		{
			move_num = -move_num;
			for (int i = 0; i < move_num; i++)
			{
				arr.push_front(arr.back());
				arr.pop_back();
			}
		}
	}
}
