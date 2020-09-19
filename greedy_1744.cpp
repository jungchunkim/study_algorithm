#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N; // 수열의 크기
	int num;
	int sum = 0;

	cin >> N;	// 수열의 크기 입력
	int *arr = new int[N];

	for (int i = 0; i < N; i++)
	{// 배열에 수열 입력한 것 저장.
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr + N);

	while (N>0)
	{
		if (N > 2)
		{
			if (arr[N - 1] * arr[N - 2] > 0)
			{	// 음양양, 음음음 일때
				if (arr[N - 2] == 1)
				{
					sum += arr[N - 1] + arr[N - 2];
					N = N - 2;
				}
				else
				{
					sum += arr[N - 1] * arr[N - 2];
					N = N - 2;
				}
			}
			else if (arr[N - 1] * arr[N - 2] < 0)
			{	//음음양 일때
				sum += arr[N - 1];
				N = N - 1;
			}
			else
			{	
				if (arr[N-2]*arr[N-3]>0)
				{	//음음0 일때
					sum += arr[N - 2] * arr[N - 3] + arr[N - 1];
					N = N - 3;
				}
				else
				{	//음0양
					sum += arr[N - 1];
					N = N - 1;
				}
				
			}
		}
		else if (N == 2)
		{
			if (arr[N - 1] * arr[N - 2]>0)
			{
				if (arr[N - 2] == 1)
				{ // 양양 일경우에 양이 1일때
					sum += arr[N - 1] + arr[N - 2];
					N = N - 2;
				}
				else 
				{	//양양, 음음 일 경우
					sum += arr[N - 1] * arr[N - 2];
					N = N - 2;
				}
				
			}
			else if (arr[N - 1] * arr[N - 2] < 0)
			{	//음양 일때
				sum += arr[N - 1] + arr[N - 2];
				N = N - 2;
			}
			else
			{
				if (arr[N - 1] > 0)
				{	//0 양 일때
					sum += arr[N - 1];
					N = N - 2;
				}
				else
				{	//음 0 일때
					sum +=0;
					N = N - 2;
				}
			}
		}
		else
		{	//N=1인 경우
			sum += arr[N - 1];
			N = N - 1;
		}

	}

	cout << sum;
}