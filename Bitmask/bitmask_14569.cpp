#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> arr(n);

	int k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		arr[i] = vector<int>(k);
		for (int j = 0; j < k; j++)
		{
			cin >> arr[i][j];
		}
	}

	int m;
	cin >> m;
	vector<vector<int>> brr(m);
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		brr[i] = vector<int>(k);
		for (int j = 0; j < k; j++)
		{
			cin >> brr[i][j];
		}
	}

	int sol;
	int temp;
	for (int i = 0; i < m; i++)
	{
		//각 학생의 들을 수 있는 과목 ( i 로 표현 )
		sol = 0;
		for (int j = 0; j < n; j++)
		{
			if (brr[i].size() < arr[j].size())
				continue;
			temp = 0;
			//arr 배열의 값이 brr 배열에 있는지 확인해야된다.
			for (int l = 0; l < arr[j].size(); l++)
			{
				int num = arr[j][l];
				for (int u = 0; u < brr[i].size(); u++)
				{// arr 배열에 있는 값이 brr 에 있으면
					if (num == brr[i][u])
					{
						temp++;
						break;
					}
				}

			}
			// 모두 포함되면 sol++;
			if (temp == arr[j].size())
			{
				sol++;
			}

		}
		cout << sol << endl;
	}
}