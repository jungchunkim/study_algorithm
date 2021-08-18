#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	
	vector<int> brr;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		brr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());

	for (int i = 0; i < K; i++)
	{
		if (arr[0 + i] < brr[(N - 1) - i])
		{
			arr[0 + i] = brr[(N - 1) - i];
		}
		else
		{
			break;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	cout << sum;
}