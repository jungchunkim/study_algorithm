#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[20];
bool c[20 * 100000];
int n;
vector<int> arr;

void recursive(int index, int sum)
{
	if (index == n)
	{
		c[sum] = true;
		return;
	}
	

	recursive(index + 1, sum + a[index]);
	recursive(index + 1, sum);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	recursive(0, 0);

	int temp;

	sort(arr.begin(), arr.end());



	for (int i = 1;; i++)
	{
		if (c[i] == false)
		{
			cout << i;
			break;
		}
	}


}