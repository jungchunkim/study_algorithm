#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}


int main()
{
	int N, K;	// ������ ����, ������ ����
	cin >> N >> K;
	int sol = 0;

	//2���� �迭�� ������ ���Կ� ������ ������´�.
	int **arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];	// ������ ���Կ� ������ �迭�� �ִ´�.
	}

	int *brr = new int[K];
	for (int i = 0; i < N; i++)
	{
		brr[i] = arr[i][1];
	}

	sort(brr, brr + N, comp);	// ���Ե鸸 ���� ��Ƽ� ������������ �����Ͽ���.

	// ���� �߽����� ���������� �Ѵ�.
	int **real = new int*[N];
	for (int i = 0; i < N; i++)
	{
		real[i] = new int[2];
		for (int j = 0; j < N; j++)
		{
			if (brr[i] == arr[j][1])
			{
				real[i][0] = arr[j][0];
				real[i][1] = arr[j][1];
			}
		}
	}


	// ���濡 ���� �� �ִ� ���� �ִ´�.
	for (int i = 0; i < K; i++)
	{
		cin >> brr[i];	//���濡 ���� �� �ִ� ���Ը� �迭�� �ִ´�.
	}

	sort(brr, brr + K);	// ������������ brr�� �����Ѵ�.

	int temp;
	for (int i = 0; i < N; i++)
	{
		temp = real[i][0];
		for (int j = 0; j < K; j++)
		{
			if (brr[j] >= temp)
			{
				sol += real[i][1];
				brr[j] = 0;
				break;
			}
		}
	}

	cout << sol;
}