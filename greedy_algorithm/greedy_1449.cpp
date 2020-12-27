#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N; // ���� ���� ���� ����
	int L; // �������� ����
	int ans = 0;
	int j = 0;
	int index = 0;
	cin >> N >> L;
	int *arr = new int[N];

	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	
	while (index<N)
	{
		j = index + 1;
		while ((arr[j]+0.5)-(arr[index]-0.5)<=L)
		{
			j++;
		}
		ans++;
		index = j;
	}
	cout << ans;
}