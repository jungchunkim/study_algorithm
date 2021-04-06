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
	//위에서 아래로
	int N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end(),compare);
	// 그냥 sort 하고 reverse 해도 된다.
	for (int i = 0; i < N; i++)
	{
		cout << arr[i]<<" ";
	}

}