#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	//min,max �Լ� ��� ��� vector�� �̿��ؼ� ����Ǯ��
	// vector���� ������ �迭 �ϴ¹�!
	vector<vector<int>> arr;
	
	for (int i = 0; i < N; i++)
	{
		vector<int> arr1;
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;
			arr1.push_back(num);
		}

		sort(arr1.begin(), arr1.end());
		arr.push_back(arr1);
	}
	
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		if (ans < arr[i][0])
			ans = arr[i][0];
	}
	cout << ans;


}