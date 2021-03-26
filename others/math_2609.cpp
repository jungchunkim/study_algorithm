#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//2609 최대공약수와 최소공배수 
	//유클리드 호재법을 사용하자
	int a, b;

	cin >> a >> b;

	int temp, c, d;

	if (a < b)
	{
		c = b;
		d = a;
	}
	else
	{
		c = a;
		d = b;
		
	}
	
	while (d != 0)
	{
		temp = c % d;
		c = d;
		d = temp;
	}

	cout << c << "\n" << a * b / c;



}