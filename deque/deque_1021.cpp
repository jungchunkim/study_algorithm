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


		// 제일 앞이 아닌 경우, 2번할지 3번할지 정해야됨
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
		{// 2번째 수행
			
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
		{// 3번째 수행
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