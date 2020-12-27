#include <stdio.h>



int main()
{
	int N;
	int max = 0;
	scanf("%d", &N);
	int A[100000];	// 밧줄마다의 들 수 있는 최대 중량
	int count[100000] = { 0 };

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++)
	{
		count[i]++;
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (A[i] <= A[j])
					count[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (max < count[i] * A[i])
			max = count[i] * A[i];
	}

	printf("%d", max);



}