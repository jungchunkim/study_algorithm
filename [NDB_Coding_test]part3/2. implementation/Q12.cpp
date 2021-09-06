#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ũ�Ⱑ 100������ 0~100�̹Ƿ� ũ��� 101�� �ؾߵ�
//����� �迭
int arr[102][102];
//���� �迭
int brr[102][102];

bool check_arr(int x, int y)
{// ��� ��ġ�϶�
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
	{// ���� ���κ��� ��� ���� ���� ��
		return true;
	}
	if ((x > 0 && brr[x - 1][y] == 1) && brr[x + 1][y] == 1)
	{// ���� ���κ��� �ٸ� ���� ���ÿ� ����Ǿ� ���� ��
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
		//num��[x,y,a,b]
		vector<int> num = build_frame[i];
		int x = num[0];
		int y = num[1];
		int a = num[2]; // 0�� �� ��� , 1�� �� ��
		int b = num[3]; // 0�� �� ���� , 1�� �� ��ġ

		if (a == 0)
		{//����϶�
			if (b == 0)
			{// �����϶�
				arr[x][y] = 0;
				if (can_delete(x, y) == false)
				{
					arr[x][y] = 1;
				}
			}
			else
			{//��ġ�϶�
				if (check_arr(x, y))
				{
					arr[x][y] = 1;
				}
			}

		}
		else
		{//���϶�
			if (b == 0)
			{// �����϶�
				brr[x][y] = 0;
				if (can_delete(x, y) == false)
				{
					brr[x][y] = 1;
				}
			}
			else
			{//��ġ�϶�
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
		{//���
			if (arr[i][j] == 1)
			{
				answer.push_back({ i,j,0 });
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{//��
			if (brr[i][j] == 1)
			{
				answer.push_back({ i,j,1 });
			}
		}
	}

	sort(answer.begin(), answer.end());


	return answer;
}