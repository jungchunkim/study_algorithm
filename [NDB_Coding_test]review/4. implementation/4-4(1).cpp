#include <iostream>

using namespace std;


// ��ü �� ����
int arr[50][50];
int x, y, dir, N, M;

//��,��,��,��
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void turn_left()
{
	dir -= 1;
	if (dir == -1)
	{
		dir = 3;
	}
}

int main()
{
	cin >> N >> M;
	cin >> x >> y >> dir;	// ĳ���� ���� ��ġ, ����

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	arr[x][y] = 2;
	int count = 1;	// �湮�� ĭ�� ��
	int turn_time = 0;

	while (true)
	{
		// ���� ���ϱ�
		turn_left();

		int x2 = x + dx[dir];
		int y2 = y + dy[dir];

		// �� �� ���� ���
		if (arr[x2][y2] == 0)
		{
			arr[x2][y2] = 2;
			x = x2;
			y = y2;
			count++;
			turn_time = 0;
			continue;
		}
		else
		{
			turn_time++;
		}

		// ��� �� ���� ��
		if (turn_time == 4)
		{
			x = x - dx[dir];
			y = y - dy[dir];

			if (arr[x][y] == 1)
			{
				break;
			}

			turn_time = 0;
		}
	}

	cout << count;

}