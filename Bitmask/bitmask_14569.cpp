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
		//�� �л��� ���� �� �ִ� ���� ( i �� ǥ�� )
		sol = 0;
		for (int j = 0; j < n; j++)
		{
			if (brr[i].size() < arr[j].size())
				continue;
			temp = 0;
			//arr �迭�� ���� brr �迭�� �ִ��� Ȯ���ؾߵȴ�.
			for (int l = 0; l < arr[j].size(); l++)
			{
				int num = arr[j][l];
				for (int u = 0; u < brr[i].size(); u++)
				{// arr �迭�� �ִ� ���� brr �� ������
					if (num == brr[i][u])
					{
						temp++;
						break;
					}
				}

			}
			// ��� ���ԵǸ� sol++;
			if (temp == arr[j].size())
			{
				sol++;
			}

		}
		cout << sol << endl;
	}
}