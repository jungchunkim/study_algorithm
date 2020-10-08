#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int x = -1000000000;
int y = 1000000000;

void recursive(vector<int> &a, int index, int sum, int plus, int minus, int mult, int divide)
{

	

	if (plus != 0 && index != n)
	{
		recursive(a, index + 1, sum + a[index], plus - 1, minus, mult, divide);
	}
	if (minus != 0 && index != n)
	{
		recursive(a, index + 1, sum - a[index], plus, minus - 1, mult, divide);
	}
	if (mult != 0 && index != n)
	{
		recursive(a, index + 1, sum * a[index], plus, minus, mult - 1, divide);
	}
	if (divide != 0 && index != n)
	{
		recursive(a, index + 1, sum / a[index], plus, minus, mult, divide - 1);
	}
	if (index == n)
	{
		if (sum > x)
			x = sum;
		if (sum < y)
			y = sum;
	}
}

int main()
{
	
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vector<int> oper(4);

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	recursive(arr, 1, arr[0], oper[0], oper[1], oper[2], oper[3]);
	cout << x << endl << y;

}