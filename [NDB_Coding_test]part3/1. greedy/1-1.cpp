#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int N;
	cin >> N;
	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end(), compare);
	

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (i + arr[i] <= N )
		{
			count++;
			i = i + arr[i] - 1;
		}
	}

	cout << count;

}