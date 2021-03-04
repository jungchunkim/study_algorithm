#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
	//�˰����� Ǯ �� ���� �̱� ������ ȯ���̱� ������ Ǯ���൵ �ȴ�.
	// c�� stdio�� cpp�� iostream�� ����ȭ�� ��Ȱ��ȭ���� �ӵ��� ������ �Ѵ�. ( ���������� ����ؼ� ������ ���� �پ��, ����ȭ -> ��Ȱ��ȭ ) 
	ios_base::sync_with_stdio(0);
	// cin�� cout�� ������ Ǯ���־�  �ӵ� ����!! ���۸� �̸� �� ����൵ ��
	cin.tie(0);

	int n, len;

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		char a[50];
		cin >> a;
		len = strlen(a);

		stack<char> b;

		for (int j = 0; j < len; j++)
		{
			if (b.empty() || a[j]=='(')
			{
				b.push(a[j]);
			}
			else if (a[j] == ')' && b.top() == '(')
			{
				b.pop();
			}
		}

		if (b.empty())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}