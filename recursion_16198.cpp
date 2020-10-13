#include <iostream>
#include <vector>

using namespace std;

int sol;

void recursion(vector<int> &a,int sum, int num)
{

	if (num == 2)
	{
		if (sum > sol)
			sol = sum;
		return;
	}
		

	for (int index = 1; index < num - 1; index++)
	{
		int temp;
		// 합을 넣는 변수
		temp = sum + a[index - 1] * a[index + 1];
		//한 칸씩 앞으로 당겨오는 for문 
		vector<int> b(num - 1);
		for (int k = 0; k < index; k++)
		{
			b[k] = a[k];
		}
		for (int i = index; i < num-1; i++)
		{
			b[i] = a[i + 1];
		}
		// 다시 recursion 함수
		recursion(b, temp, num - 1);
	}
}


int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	recursion(arr, 0, n);

	cout << sol;
}