#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	//push(element):큐에 원소를 추가 (뒤에)
	//pop():제일 앞에 있는 원소 삭제

	int T;
	int N, M; // 문서의 개수 N, 몇 번째로 인쇄되는지 M
	int num;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		queue<int> q;
		vector<int> arr;
		cin >> N >> M;
		int count = 0;

		for (int j = 0; j < N; j++)
		{
			cin >> num;
			arr.push_back(num);
			q.push(num);

		}
		int index = (arr.size()) - 1;
		sort(arr.begin(), arr.end());

		while (1)
		{
			if (q.front() == arr[index])
			{// 앞에 있는 것이 제일 클 때
				q.pop();
				count++;
				index--;
				if ((M - 1) >= 0)
				{
					M--;
				}
				else
				{//M이 제일 앞 일 때
					break;
				}
			}
			else
			{// 아닐때
				q.push(q.front());
				q.pop();
				if ((M - 1) >= 0)
				{
					M--;
				}
				else
				{//M이 제일 앞 일 때
					M = q.size() - 1;
				}
			}
		}

		cout << count << "\n";
	}
}