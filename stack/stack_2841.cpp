#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int N, P;	//���� �� N, ������ �� P
	cin >> N >> P;
	int count = 0;
	stack<int> arr1[7];
	

	int num_n, num_p;
	for (int i = 0; i < N; i++)
	{
		cin >> num_n >> num_p;

		if (arr1[num_n].empty())
		{// ������� ���
			arr1[num_n].push(num_p);			
			count++;	
			continue;
		}
		else
		{// �� ������� ���
			while (1)
			{
				if (arr1[num_n].empty())
				{
					arr1[num_n].push(num_p);				
					count++;
					break;
				}
				else if (arr1[num_n].top() < num_p)
				{// ���� ���� �ִ� ������ Ŭ ��� �׳� �������
					arr1[num_n].push(num_p);
					count++;		
					break;
				}
				else if (arr1[num_n].top() == num_p)
				{// ���� ���� �ִ� ������ ���� �� �� ���ߵ�
					break;
				}
				else
				{
					arr1[num_n].pop();
					count++;
				}
			}
		}
	}

	cout << count;
}