#include <stdio.h>



int main()
{
	int count = 0;
	int money;
	int total = 1000;
	int i;

	scanf("%d", &money);

	while (total != 0)
	{
		if (total - 500 >= 0)
		{
			count++;
			total = total - 500;
		}
		else if (total - 100 >= 0)
		{
			count++;
			total = total - 100;
		}
		else if (total - 50 >= 0)
		{
			count++;
			total = total - 50;
		}
		else if (total - 10 >= 0)
		{
			count++;
			total = total - 10;
		}
		else if (total - 5 >= 0)
		{
			count++;
			total = total - 5;
		}
		else
		{
			count++;
			total = total - 1;
		}

	}

	printf("%d", count);

}