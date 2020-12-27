#include <stdio.h>
int N, M;
int arr[9];

int promising(int i)
{
	int j = 1;
	int a = 1;	//bool ´ë½Å

	while (j < i && a)
	{
		if (arr[i] == arr[j])
		{
			a = 0;
		}
		j++;
	}
	return a;

}

void back_tracking(int i)
{
	int j;
	if (promising(i))
	{
		if (i == M)
		{
			for (j = 1; j <= M; j++)
				printf("%d ", arr[j]);
			printf("\n");
			return;
		}
		else
		{
			for (j = 1; j <= N; j++)
			{
				arr[i + 1] = j;
				back_tracking(i + 1);
			}
		}

	}

}

int main(void)
{
	scanf("%d", &N);
	scanf("%d", &M);

	back_tracking(0);

	return 0;

}