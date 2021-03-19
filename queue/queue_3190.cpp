#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

int map[101][101];

vector<pair<int, char>>v;
deque<pair<int, int>>dq;

void func();

int n, time;

int main()
{
	int k, y, x, l, num;
	char c;

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> y >> x;
		map[y][x] = 1;
	}

	cin >> l;
	for (int i = 1; i <= l; i++)
	{
		cin >> num >> c;
		v.push_back(make_pair(num, c));
	}

	func();
	cout << time << endl;
}
void func()
{
	//cnt= 연산의 갯수
	int y = 1, x = 1, go = 0, cnt = 0;

	dq.push_back({ y,x });

	map[y][x] = 2;

	while (1)
	{
		time++;
		int nx = x + dx[go];
		int ny = y + dy[go];

		//벽이나, 자신의 몸의일부만나면 끝
		if (nx<1 || ny<1 || nx>n || ny>n || map[ny][nx] == 2)
			return;
		else if (map[ny][nx] == 0)
		{//아무것도 아닌 부분 지나간 경우
			map[ny][nx] = 2;
			map[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
			dq.push_front({ ny,nx });
		}
		else if (map[ny][nx] == 1)
		{//사과 있는 부분 지나간 경우
			map[ny][nx] = 2;
			dq.push_front({ ny,nx });
		}

		if (cnt < v.size()) {
			//연산 횟수에 대해 방향갱신
			if (time == v[cnt].first)
			{
				if (v[cnt].second == 'L')
					go = (go + 1) % 4;
				else if (v[cnt].second == 'D')
					go = (go + 3) % 4;
				cnt++;
			}
		}
		y = ny;
		x = nx;
	}
}