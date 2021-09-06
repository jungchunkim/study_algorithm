#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[102][102];

int dx[] = { 0, 1,0,-1 };
int dy[] = { 1,0,-1,0 };


int main()
{
	int N;
	cin >> N;
	// 벽을 -1로 만듬!
	for (int i = 0; i <= N + 1; i++)
	{
		arr[0][i] = -1;
		arr[i][0] = -1;
		arr[N + 1][i] = -1;
		arr[i][N + 1] = -1;
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	vector<pair<int, char>> dir;
	int L;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		dir.push_back({ a,b });
	}

	int cur_time = 0;
	int cur_dir = 0;

	//dir 배열에 대한 index
	int change_index = 0;
	int change_time = dir[change_index].first;
	

	int cur_x = 1;
	int cur_y = 1;

	arr[cur_x][cur_y] = 2;

	queue<pair<int, int>> tail;
	tail.push({ cur_x,cur_y });

	while (true)
	{
		cur_time++;

		//이동한 위치
		cur_x += dx[cur_dir];
		cur_y += dy[cur_dir];

		if (arr[cur_x][cur_y] == -1 || arr[cur_x][cur_y]==2)
		{
			// 벽에 부딪힌 경우 || 자기 몸에 부딪힌 경우 
			break;
		}

		tail.push({ cur_x,cur_y });
		// 사과가 있는 경우
		if (arr[cur_x][cur_y] == 1)
		{
			arr[cur_x][cur_y] = 2;
		}
		else
		{
			arr[cur_x][cur_y] = 2;
			//꼬리 잘라야됨
			pair<int, int> num = tail.front();
			arr[num.first][num.second] = 0;
			tail.pop();
		}

		if (change_index < L && cur_time == change_time)
		{
			// 방향 바꾸는 시간이면
			if (dir[change_index].second == 'D')
			{
				//'D'일때
				cur_dir++;
				if (cur_dir == 4)
				{
					cur_dir = 0;
				}
			}
			else
			{
				//'L'일때
				cur_dir--;
				if (cur_dir == -1)
				{
					cur_dir = 3;
				}
			}

			change_index++;
			if (change_index < L)
			{
				change_time = dir[change_index].first;
			}
		}
		
	}


	cout << cur_time;
}