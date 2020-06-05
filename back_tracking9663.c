#include <stdio.h>
#include <stdlib.h>

int count = 0;
int N;
int col[16];

int promising(int i)
{
	int j = 1;
	int a = 1;

	while (j < i&&a)
	{
		if (col[j] == col[i] || abs(col[i] - col[j]) == i - j)
			a = 0;
		j++;
	}
	return a;
}


void queen(int i)
{
	int j;
	if (promising(i))
	{
		if (i == N)
		{
			count++;
			return;
		}
		else
		{
			for (j=1;j<=N;j++)
			{
				col[i + 1] = j;
				queen(i + 1);
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	queen(0);
	printf("%d", count);

	return 0;
}