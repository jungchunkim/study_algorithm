#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N; // ������ ũ��
	int num;
	int sum = 0;

	cin >> N;	// ������ ũ�� �Է�
	int *arr = new int[N];

	for (int i = 0; i < N; i++)
	{// �迭�� ���� �Է��� �� ����.
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr + N);

	while (N>0)
	{
		if (N > 2)
		{
			if (arr[N - 1] * arr[N - 2] > 0)
			{	// �����, ������ �϶�
				if (arr[N - 2] == 1)
				{
					sum += arr[N - 1] + arr[N - 2];
					N = N - 2;
				}
				else
				{
					sum += arr[N - 1] * arr[N - 2];
					N = N - 2;
				}
			}
			else if (arr[N - 1] * arr[N - 2] < 0)
			{	//������ �϶�
				sum += arr[N - 1];
				N = N - 1;
			}
			else
			{	
				if (arr[N-2]*arr[N-3]>0)
				{	//����0 �϶�
					sum += arr[N - 2] * arr[N - 3] + arr[N - 1];
					N = N - 3;
				}
				else
				{	//��0��
					sum += arr[N - 1];
					N = N - 1;
				}
				
			}
		}
		else if (N == 2)
		{
			if (arr[N - 1] * arr[N - 2]>0)
			{
				if (arr[N - 2] == 1)
				{ // ��� �ϰ�쿡 ���� 1�϶�
					sum += arr[N - 1] + arr[N - 2];
					N = N - 2;
				}
				else 
				{	//���, ���� �� ���
					sum += arr[N - 1] * arr[N - 2];
					N = N - 2;
				}
				
			}
			else if (arr[N - 1] * arr[N - 2] < 0)
			{	//���� �϶�
				sum += arr[N - 1] + arr[N - 2];
				N = N - 2;
			}
			else
			{
				if (arr[N - 1] > 0)
				{	//0 �� �϶�
					sum += arr[N - 1];
					N = N - 2;
				}
				else
				{	//�� 0 �϶�
					sum +=0;
					N = N - 2;
				}
			}
		}
		else
		{	//N=1�� ���
			sum += arr[N - 1];
			N = N - 1;
		}

	}

	cout << sum;
}