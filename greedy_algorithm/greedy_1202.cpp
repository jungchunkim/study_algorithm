#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}


int main()
{
	int N, K;	// 보석의 개수, 가방의 개수
	cin >> N >> K;
	int sol = 0;

	//2차원 배열에 보석의 무게와 가격을 적어놓는다.
	int **arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];	// 보석의 무게와 가격을 배열에 넣는다.
	}

	int *brr = new int[K];
	for (int i = 0; i < N; i++)
	{
		brr[i] = arr[i][1];
	}

	sort(brr, brr + N, comp);	// 무게들만 따로 모아서 내림차순으로 정렬하였다.

	// 무게 중심으로 내림차순을 한다.
	int **real = new int*[N];
	for (int i = 0; i < N; i++)
	{
		real[i] = new int[2];
		for (int j = 0; j < N; j++)
		{
			if (brr[i] == arr[j][1])
			{
				real[i][0] = arr[j][0];
				real[i][1] = arr[j][1];
			}
		}
	}


	// 가방에 넣을 수 있는 무게 넣는다.
	for (int i = 0; i < K; i++)
	{
		cin >> brr[i];	//가방에 담을 수 있는 무게를 배열에 넣는다.
	}

	sort(brr, brr + K);	// 오름차순으로 brr을 정렬한다.

	int temp;
	for (int i = 0; i < N; i++)
	{
		temp = real[i][0];
		for (int j = 0; j < K; j++)
		{
			if (brr[j] >= temp)
			{
				sol += real[i][1];
				brr[j] = 0;
				break;
			}
		}
	}

	cout << sol;
}