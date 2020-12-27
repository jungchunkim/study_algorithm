#include <stdio.h>
#include <conio.h>

/*
작성 날짜 : 2020-04-28
작성자 : 김정천
함수 이름 :ReadNum
기능: 정수 하나를 입력받고 반환한다.
인자: void
반환값: 입력 받은 정수
*/
int ReadNum() 
{
	int num;	//정수를 입력받을 변수 선언
	scanf("%d", &num);	//정수를 하나 입력받는다.
	return num;	//입력받은 정수를 리턴해준다.
}


/*
함수 이름 :max_num
기능: 두 수의 합과 곱 중 큰 수를 찾는다.
인자: int num1: 첫 번째 정수
	  int num2: 두 번째 정수
반환값: 두 수의 곱한 값과 더한 값 중에 큰 수
*/
int max_num(int num1, int num2) {
	int mult = num1 * num2;	// 두 수의 곱한 값을 mult 변수에 저장한다.
	int add = num1 + num2;	// 두 수의 더한 값을 mult 변수에 저장한다.

	/*
	곱한 값이 더한 값보다 크면 mult 출력,
	같거나 작으면 add를 출력하는 if-else문을 사용한다.
	*/
	if (mult > add)	
		return mult;	// 곱한 값을 출력한다.
	else
		return add;		// 더한 값을 출력한다.
}


/*
함수 이름: main
기능:  두 수를 입력받고 두 수의 합과 곱 중 큰 수를 찾는 연산을 한다.
인자 : void
반환값: 0
.*/
int main(void)
{
	int num1, num2, max;	//정수를 받을 변수와 두 수의 합과 곱 중 큰 수를 닮을 변수 3개를 선언한다.

	printf("두 수를 입력하시오 :");
	num1 = ReadNum();	//정수 하나를 입력받는다.(ReadNum() 이용)
	num2 = ReadNum();	//정수 하나를 입력받는다.(ReadNum() 이용)

	max = max_num(num1, num2);	//곱과 합 중에서 큰 수를 받는다. (max_num() 이용)
	printf("%d 과 %d의 곱과 합 중에서 큰 수는 %d 입니다", num1, num2, max);	//

	_getch();
	return 0;
}