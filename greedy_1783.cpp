#include <iostream>
#include <algorithm>

using namespace std;

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main()
{
	// �׸��� �˰��� : ������ ����� ���� ��� �����ִ� ������ ��������.
	int N, M;

	cin >> N >> M;

	if (N == 1)
		cout << 1;
	else if (N == 2)
		cout << min(4, (1 + M) / 2);
	else
	{
		//N�� 3 �̻��� ��, width ũ�� ���� �޶���
		if (M > 7)
			cout << 4 + (M - 7);
		else
			cout << min(4, M);
	}
}