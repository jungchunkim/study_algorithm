#include <stdio.h>

int main(void)
{
	int N,temp,temp2,sol=0;
	
	scanf("%d", &N);

	if (N == 0)
	{
		sol++;
		printf("%d", sol);
		return 0;
	}

	if (N < 10)
		N = N * 10;
	temp2 = N;
	while (1)
	{
		
		int a, b, c;
		sol++;
		a = temp2 / 10;
		b = temp2 % 10;
		c = (a+b) % 10;
		temp = b * 10 + c;

		if (temp == N)
			break;
		temp2 = temp;
	}
	printf("%d", sol);
	return 0;
}