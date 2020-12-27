#include <stdio.h>
#include <conio.h>

/*
작성날짜 2020-04-24
작성자:김정천(B611045)
함수 이름: main
기능: 5가지 종류의 출력패턴을 반복문과 조건문을 이용하여 구현한다.
인자 : void
반환값 : 0
*/
int main(void)
{
	int num;	    // 양의 홀수를 받을 변수 선언한다.
	int i, j, k;	// 반복문에 쓸 index를 선언한다.
	int space;      // 다섯 번째 패턴에 쓰일 공간의 개수를 받을 변수
	int temp;		// index를 받을 추가 변수


	printf("양의 홀수 하나를 입력하시오: ");	
	scanf("%d", &num); // 키보드로부터 양의 홀수를 하나를 입력받는다.

	/*
	첫 번째 패턴
	줄이 아래로 갈때마다 숫자의 개수가 하나씩 감소한다.
	숫자가 뒤에서부터 하나씩 없어진다.
	*/
	for (i = num - 1; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{ //뒤에서부터 숫자가 하나씩 없어져서 j의 범위를 0~i 로 지정한다.
			printf("%d", j);
		}
		printf("\n");
	}
	printf("\n");


	/*
	두 번째 패턴
	줄이 아래로 갈때마다 숫자의 개수가 하나씩 감소한다.
	숫자가 앞에서부터 하나씩 없어진다.
	*/
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{//앞에서부터 숫자가 없어져서 j의 범위를 i~num-1으로 지정한다.
			printf("%d", j);
		}

		printf("\n");

		for (k = 0; k <= i; k++)
		{// 공백은 줄이 아래로 내려갈수록 한 칸씩 추가된다. 따라서 k의 범위를 0~i로 지정한다.
			printf(" ");
		}

	}
	printf("\n");

	/*
	세 번째 패턴
	아래로 내려갈수록 숫자의 개수는 한 개씩 증가,
	숫자의 앞에 있는 공백만 신경쓰면 되므로 짝수번째 줄만 고려하자.
	*/
	for (i = 0; i < num; i++)
	{

		if (i % 2 != 0)
		{//공백을 만들어주는 for문, i가 홀수일 때(짝수 줄) 공백이 num-i-1만큼 있다.
			for (k = 0; k < num - i - 1; k++)
			{
				printf(" ");
			}
		}

		for (j = 0; j <= i; j++)
		{//줄에 있는 숫자가 통일되므로 i 값을 출력한다.
			printf("%d", i);
		}

		printf("\n");
	}
	printf("\n");


	/*
	네 번째 패턴
	첫 번째 줄과 마지막 줄 & 그 사이에 있는 줄 두 가지로 나눠준다.
	if-else 문을 사용하여 위의 두 조건으로 나눠준다.
	*/
	for(i=0;i<num;i++)
	{
		if ((i == 0) || (i == num-1))
		{//첫 번째 줄과 마지막 줄은 공백없이 채워준다.
			for (j = 0; j < num; j++)
				printf("%d", i);
		}
		else
		{//첫 번째와 마지막 줄 사이에 있는 줄은 양쪽에만 숫자를 적고 중간은 공백으로 채워준다.
			printf("%d", i);
			for (j = 0; j < num-2; j++)
			{//공백을 num-2만큼 채워준다.
				printf(" ");
			}
			printf("%d", i);
		}

		printf("\n");
	}

	printf("\n");


	/*
	다섯 번째 패턴
	공백의 패턴: 제일 위에 줄의 앞쪽 공백이 num/2이고 
	줄이 내려갈수록 한 개씩 감소하다가 0을 도착하고 다시 반대로 증가하는 패턴이다.
	줄 마다 숫자의 개수: num에서 양쪽 공백을 빼준다.
	*/
	space = num / 2 + 1; //숫자 앞의 공백을 받을 변수 
	for (i = 0; i < num; i++)
	{
		space--;	  //줄이 바껴서 space 값을 감소시킨다.
		temp = space; //space의 값을 담을 변수, 매 반복마다 space값으로 초기화한다.
		if (space > 0)
		{//space 가 양수일 때 숫자 앞의 공백은 temp 만큼 있다.
			for (j = 0; j <temp ; j++)
			{
				printf(" ");
			}
		}
		else
		{//space=0일 때는 공백이 없다. 
			if (space < 0)
			{//space<0일 때, space의 절대값을 temp에다가 넣어준다.
				temp = -space;
				for (j = 0; j < temp; j++)
				{//temp(space의 절대값)만큼 공백을 만든다. 
					printf(" ");
				}
			}			
		}

		for (j = 0; j < num - 2 * temp; j++)
		{// 숫자의 개수가 num-2*temp만큼 있다.(num - 앞의 공백*2)
			printf("%d", i);
		}
		printf("\n");
	}

	_getch();
	return 0;
}