#include <iostream>
#include <vector>
#define num_max 4*100-3

using namespace std;

char starmap[num_max][num_max];

int N;

void recursion(int num)
{
	for (int i = 0; i < 4*num-3; i++)
	{
		int point = N - num;
		if (i == 0 || i == (4 * num - 4))
		{//첫번째와 마지막
			for (int j = 0; j < 4 * num - 3; j++)
			{
				starmap[2 * point+i][2*point+j] = '*';
				
			}
		}
		else
		{//중간에 있는 것
			for (int j = 0; j < 4 * num - 3; j++)
			{
				if (j == 0 || j == (4 * num - 4))
				{
					starmap[2 * point + i][2 * point + j] = '*';
			
				}
				else
				{
					starmap[2 * point + i][2 * point + j] = ' ';
				
				}
			}
		}
	}
	
	if (num == 1)
	{
		return;
	}
	else
	{
		recursion(num-1);
	}
}

int main()
{
	// 반복문 말고 recursion을 사용해서 풀어보자

	cin >> N;

	recursion(N);


	for (int i = 0; i < 4 * N - 3; i++)
	{
		for (int j = 0; j < 4 * N - 3; j++)
		{
			cout << starmap[i][j];
		}
		cout << "\n";
	}
}
