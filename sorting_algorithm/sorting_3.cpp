#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> arr;
	vector<int> brr;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		brr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());

	for (int i = 0; i < K; i++)
	{
		if (arr[i] < brr[(N - 1) - i])
			arr[i] = brr[(N - 1) - i];
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