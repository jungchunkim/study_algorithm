#include <iostream>

using namespace std;

int b[1001];

int main()
{
	int n, a = 0;
	cin >> n;
	//�ʱⰪ�� ��������
	b[1] = 1;
	b[2] = 2;
	//dp ������ Ǯ���
	for (int i = 3; i <= n; i++)
	{
		b[i] = (b[i - 1] + b[i - 2]) % 10007;
	}

	cout << b[n];
}