#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[100];// 최대의 식량이 담겨있는 배열 

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
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);

	for (int i = 2; i < N; i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
	}

	cout << d[N - 1];

}