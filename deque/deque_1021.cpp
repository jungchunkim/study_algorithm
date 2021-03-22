#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> arr;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		arr.push_back(i);
	}

	int num;
	int count = 0;
	while (M--)
	{
		cin >> num;


		// ���� ���� �ƴ� ���, 2������ 3������ ���ؾߵ�
		int index;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == num)
			{
				index = i;
				break;
			}
		}

		if (index < arr.size() - index)
		{// 2��° ����
			
			while (1)
			{
				if (arr.front() == num)
				{
					arr.pop_front();
					break;
				}
				arr.push_back(arr.front());
				arr.pop_front();
				count++;
			}
		}
		else
		{// 3��° ����
			while (1)
			{
				if (arr.front() == num)
				{
					arr.pop_front();
					break;
				}
				arr.push_front(arr.back());
				arr.pop_back();
				count++;
			}
			
		}

	}

	cout << count;
}