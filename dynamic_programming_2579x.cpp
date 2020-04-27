#include <iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main() 
{
	int n;
	cin >> n;//  입력의 개수
	int k = 0;
	int *num = new int[n];
	int sum = 0;

	for (int i = 0; i < n-3; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++)
	{
		if (k == 0)
		{
			num[i + 1] += num[i];
			k++;
		}
		else
		{
			num[i + 2] += num[i];
			k = 0;
		}

	}
	printf("%d", num[0]);
	cout << num[n-1];


	


}