#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//2609 �ִ������� �ּҰ���� 
	//��Ŭ���� ȣ����� �������
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