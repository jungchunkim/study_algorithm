#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	cin >> N;
	int *arr = new int[N];
	int temp = 1;
	int sol = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	if (N == 1)
	{
		cout << 0;
	}
	else
	{
		int last = arr[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			if (arr[i] < last - temp)
			{// 작은 경우일 때
				temp += (last - temp) - arr[i];
				temp++;
			}
			else if (arr[i] == last - temp)
			{
				temp++;
			}
			else
			{// 더 큰 경우
				while (arr[i]!=last-temp)
				{
					arr[i]--;
					sol++;
				}
				temp++;
			}

		}

		cout << sol;
	}
	

	

}