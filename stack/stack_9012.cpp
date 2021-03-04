#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
	//알고리즘을 풀 때 보통 싱글 스레드 환경이기 때문에 풀어줘도 된다.
	// c의 stdio와 cpp의 iostream을 동기화를 비활성화시켜 속도를 빠르게 한다. ( 독립적으로 사용해서 버퍼의 수가 줄어들어서, 동기화 -> 비활성화 ) 
	ios_base::sync_with_stdio(0);
	// cin과 cout의 묶음을 풀어주어  속도 개선!! 버퍼를 미리 안 비워줘도 됨
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