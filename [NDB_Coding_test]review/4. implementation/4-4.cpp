#include <iostream>

using namespace std;


// ��ü �� ����
int arr[50][50];

//��,��,��,��
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main()
{
	int N, M;
	cin >> N >> M;
	int x, y, dir;
	int count = 0;	// �湮�� ĭ�� ��
	cin >> x >> y >> dir;	// ĳ���� ���� ��ġ, ����

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	arr[x][y] = 2;
	count++;

	while (true)
	{
		// ���� ���ϱ�
		int temp = dir;
		if (temp - 1 < 0)
		{
			temp = 3;
		}
		else
		{
			temp--;
		}
		
		int k = 0;
		while (temp != dir)
		{// ���� ���� ������ ������
			int x2 = x + dx[temp];
			int y2 = y + dy[temp];
			
			// �� �� ���� ���
			if (arr[x2][y2] == 0)
			{
				arr[x2][y2] = 2;
				x = x2;
				y = y2;
				count++;
				dir = temp;
				k = 1;
				break;
			}
			if (temp - 1 < 0)
			{
				temp = 3;
			}
			else
			{
				temp--;
			}
		}

		if (temp == dir && k == 0)
		{
			int x2 = x + dx[temp];
			int y2 = y + dy[temp];

			if (arr[x2][y2] == 0 )
			{//�� �� �ִ� ���
				arr[x2][y2] = 2;
				x = x2;
				y = y2;
				count++;
			}
			else
			{//���� ���� ��� �ڷ� ���ߵ�
				temp--;
				if (temp < 0)
				{
					temp = 3;
				}
				temp--;
				if (temp < 0)
				{
					temp = 3;
				}
				
				x = x + dx[temp];
				y = y + dy[temp];

				if (arr[x][y] == 1)
				{
					break;
				}
			}
		}
	}

	cout << count;

}