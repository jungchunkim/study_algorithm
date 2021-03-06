#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	//push(element):ť�� ���Ҹ� �߰� (�ڿ�)
	//pop():���� �տ� �ִ� ���� ����

	int T;
	int N, M; // ������ ���� N, �� ��°�� �μ�Ǵ��� M
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
			{// �տ� �ִ� ���� ���� Ŭ ��
				q.pop();
				count++;
				index--;
				if ((M - 1) >= 0)
				{
					M--;
				}
				else
				{//M�� ���� �� �� ��
					break;
				}
			}
			else
			{// �ƴҶ�
				q.push(q.front());
				q.pop();
				if ((M - 1) >= 0)
				{
					M--;
				}
				else
				{//M�� ���� �� �� ��
					M = q.size() - 1;
				}
			}
		}

		cout << count << "\n";
	}
}