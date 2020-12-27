#include <iostream>
#include <algorithm>
using namespace std;



int main() 
{
	int n,k;
	int j = 0;
	int sum = 0;
	cin >> n;
	int *temp = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		temp[i] = k;
	}

	sort(temp, temp + n);

	for (int i = n; i >=1; i--)
	{
		sum += temp[j] * i;
		j++;
	}

	cout << sum;

}