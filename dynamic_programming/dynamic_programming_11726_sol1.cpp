#include <iostream>

using namespace std;

int b[1000];

int main()
{
	int n, a = 0;
	cin >> n;
	//�ʱⰪ�� ��������
	b[0] = 1;
	b[1] = 2;
	while (1)
	{
		if (n <= 2)
		{
			break;
		}
		else
		{
			b[a + 2] = (b[a] + b[a + 1])%10007;
			if (n == (a + 3))
			{
				break;
			}
			else
			{
				a++;
			}

		}
	}

	if (n <= 2)
	{
		cout << n;
	}
	else
	{
		cout << (b[a + 2]);
	}

}