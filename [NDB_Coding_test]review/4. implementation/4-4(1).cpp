#include <iostream>

using namespace std;


// 전체 맵 정보
int arr[50][50];
int x, y, dir, N, M;

//북,동,남,서
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
	cin >> x >> y >> dir;	// 캐릭터 시작 위치, 방향

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	arr[x][y] = 2;
	int count = 1;	// 방문한 칸의 수
	int turn_time = 0;

	while (true)
	{
		// 방향 정하기
		turn_left();

		int x2 = x + dx[dir];
		int y2 = y + dy[dir];

		// 갈 수 있을 경우
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

		// 모두 못 갔을 때
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