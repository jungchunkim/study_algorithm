#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool visited[10000];

pair<int,string> trans(int start, int k)
{
	int x;
	pair<int, string> r;
	if (start == 0)
	{// ��ɾ� 'D' �� ���
		x = 2 * k;
		if (x > 9999)
			x = x - 10000;
		r = make_pair(x, 'D');
		return r;
	}
	else if (start == 1)
	{// ��ɾ� 'S' �� ���
		x = k - 1;
		if (x == -1)
			x = 9999;
		r = make_pair(x, 'S');
		return r;
	}
	else if (start == 2)
	{//�� �ڸ����� �������� ȸ��, L�� ���
		int y;
		if (k >= 1000)
		{
			y = k % 1000;
			x = (y * 10) + (k / 1000);
			r = make_pair(x, 'L');
			return r;
		}
		else 
		{
			x = k * 10;
			r = make_pair(x, 'L');
			return r;
		}
	}
	else
	{// �� �ڸ����� ���������� ȸ��, R�� ���
		int y;
		y = k / 10;
		x = k % 10;
		r = make_pair((1000 * x) + y, 'R');
		return  r;
	}
}
 

int main()
{
	int T, A, B;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		memset(visited, false, sizeof(visited));

		queue<pair<int,string>> q;
		q.push(pair<int,string>(A,""));
		visited[A] = true;
		
		int tag = 0;
		while (tag == 0)
		{
			pair<int,string> k = q.front();

			int a = k.first;
			string b = k.second;
			
			q.pop();
			if (a == B)
			{
				cout << b << endl;
				tag = 1;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				pair<int, string> x = trans(i, a);

				int c = x.first;
				string d = b + x.second;

				if (!visited[c])
				{
					if (c == B)
					{// ���� ��� ť�� �ִ°� �� ��
						cout << d << endl;
						tag = 1;
						break;
					}
					else
					{
						visited[c] = true;
						q.push(pair<int, string>(c, d));
					}
				}
				
			}

		}
	}
}