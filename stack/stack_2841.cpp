#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int N, P;	//음의 수 N, 프렛의 수 P
	cin >> N >> P;
	int count = 0;
	stack<int> arr1[7];
	

	int num_n, num_p;
	for (int i = 0; i < N; i++)
	{
		cin >> num_n >> num_p;

		if (arr1[num_n].empty())
		{// 비어있을 경우
			arr1[num_n].push(num_p);			
			count++;	
			continue;
		}
		else
		{// 안 비어있을 경우
			while (1)
			{
				if (arr1[num_n].empty())
				{
					arr1[num_n].push(num_p);				
					count++;
					break;
				}
				else if (arr1[num_n].top() < num_p)
				{// 제일 위에 있는 값보다 클 경우 그냥 넣으면됨
					arr1[num_n].push(num_p);
					count++;		
					break;
				}
				else if (arr1[num_n].top() == num_p)
				{// 제일 위에 있는 값보다 작을 때 손 떼야됨
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