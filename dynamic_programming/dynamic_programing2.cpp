#include <iostream>
using namespace std;

int count_0[41] = { 1,0 };
int count_1[41] = { 0,1 };


int main()
{
	int n, k;
	cin >> n;
	int *num = new int[n];
	for (int i = 2; i <= 41; i++)
	{
		count_0[i] = count_0[i - 2] + count_0[i - 1];
		count_1[i] = count_1[i - 2] + count_1[i - 1];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		num[i] = k;
	}
	for (int i = 0; i < n; i++)
	{
		
		cout << count_0[num[i]] << " " << count_1[num[i]] << endl;
		
	}
}