#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[7][7];
char temp[7][7];
int N;
bool ret = true;

void move_top(int x, int y) {
	if (x == 0 || temp[x][y] == 'O') {
		return;
	}
	if (temp[x][y] == 'S') {
		ret = false;
		return;
	}
	move_top(x - 1, y);
}
void move_down(int x, int y) {

	if (x == N + 1 || temp[x][y] == 'O') {
		return;
	}

	if (temp[x][y] == 'S') {
		ret = false;
		return;
	}
	move_down(x + 1, y);
}
void move_right(int x, int y) {
	if (y == N + 1 || temp[x][y] == 'O') {
		return;
	}

	if (temp[x][y] == 'S') {
		ret = false;
		return;
	}
	move_right(x, y + 1);
}
void move_left(int x, int y) {
	if (y == 0 || temp[x][y] == 'O') {
		return;
	}
	if (temp[x][y] == 'S') {
		ret = false;
		return;
	}
	move_left(x, y - 1);

}


void dfs(int x, int y) {
	//위로 가는거, 밑으로 가는거, 오른쪽으로 가는거, 왼쪽으로 가는거

	move_top(x-1, y);
	move_down(x+1, y);
	move_right(x, y+1);
	move_left(x, y-1);
}


int main()
{
	
	cin >> N;

	vector<pair<int, int>> brr;
	vector<pair<int, int>> teacher;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') {
				teacher.push_back({ i,j });
			}
			if (arr[i][j] == 'X') {
				brr.push_back({ i,j });
			}
		}
	}

	vector<int> crr(brr.size(), 0);
	crr[0] = 1;
	crr[1] = 1;
	crr[2] = 1;


	do {
		

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < crr.size(); i++) {
			if (crr[i] == 1) {
				temp[brr[i].first][brr[i].second] = 'O';
			}
		}

		ret = true;
		for (int i = 0; i < teacher.size(); i++) {
			int num_x = teacher[i].first;
			int num_y = teacher[i].second;
			
			dfs(num_x, num_y);
		}
		if (ret == true) {
			break;
		}

	} while (prev_permutation(crr.begin(), crr.end()));

	if (ret == true)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}