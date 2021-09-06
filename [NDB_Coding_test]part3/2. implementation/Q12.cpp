#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 크기가 100이지만 0~100이므로 크기는 101로 해야됨
//기둥의 배열
int arr[102][102];
//보의 배열
int brr[102][102];

bool check_arr(int x, int y)
{// 기둥 설치일때
	if (y == 0 || (x > 0 && brr[x - 1][y]) || brr[x][y])
	{
		return true;
	}
	if (y > 0 && arr[x][y - 1] == 1)
	{
		return true;
	}

	return false;

}

bool check_brr(int x, int y)
{
	if (arr[x + 1][y - 1] == 1 || arr[x][y - 1] == 1)
	{// 한쪽 끝부분이 기둥 위에 있을 때
		return true;
	}
	if ((x > 0 && brr[x - 1][y] == 1) && brr[x + 1][y] == 1)
	{// 양쪽 끝부분이 다른 보와 동시에 연결되어 있을 때
		return true;
	}

	return false;
}

bool can_delete(int x, int y)
{
	for (int i = max(0, x - 1); i <= x + 1; i++)
	{
		for (int j = y; j <= y + 1; j++)
		{
			if (arr[i][j] && !check_arr(i, j))
			{
				return false;
			}

			if (brr[i][j] && !check_brr(i, j))
			{
				return false;
			}
		}
	}

	return true;

}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {



	for (int i = 0; i < build_frame.size(); i++)
	{
		//num은[x,y,a,b]
		vector<int> num = build_frame[i];
		int x = num[0];
		int y = num[1];
		int a = num[2]; // 0일 때 기둥 , 1일 때 보
		int b = num[3]; // 0일 때 삭제 , 1일 때 설치

		if (a == 0)
		{//기둥일때
			if (b == 0)
			{// 삭제일때
				arr[x][y] = 0;
				if (can_delete(x, y) == false)
				{
					arr[x][y] = 1;
				}
			}
			else
			{//설치일때
				if (check_arr(x, y))
				{
					arr[x][y] = 1;
				}
			}

		}
		else
		{//보일때
			if (b == 0)
			{// 삭제일때
				brr[x][y] = 0;
				if (can_delete(x, y) == false)
				{
					brr[x][y] = 1;
				}
			}
			else
			{//설치일때
				if (check_brr(x, y))
				{
					brr[x][y] = 1;
				}
			}

		}
	}
	vector<vector<int>> answer;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{//기둥
			if (arr[i][j] == 1)
			{
				answer.push_back({ i,j,0 });
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{//보
			if (brr[i][j] == 1)
			{
				answer.push_back({ i,j,1 });
			}
		}
	}

	sort(answer.begin(), answer.end());


	return answer;
}