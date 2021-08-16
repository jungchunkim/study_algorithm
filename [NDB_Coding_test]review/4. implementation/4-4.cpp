#include <iostream>

using namespace std;


// 전체 맵 정보
int arr[50][50];

//북,동,남,서
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main()
{
	int N, M;
	cin >> N >> M;
	int x, y, dir;
	int count = 0;	// 방문한 칸의 수
	cin >> x >> y >> dir;	// 캐릭터 시작 위치, 방향

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
		// 방향 정하기
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
		{// 같은 방향 나오기 전까지
			int x2 = x + dx[temp];
			int y2 = y + dy[temp];
			
			// 갈 수 있을 경우
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
			{//갈 수 있는 경우
				arr[x2][y2] = 2;
				x = x2;
				y = y2;
				count++;
			}
			else
			{//갈수 없는 경우 뒤로 가야됨
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