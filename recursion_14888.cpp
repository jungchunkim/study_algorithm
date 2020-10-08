#include <iostream>
#include <vector>

using namespace std;


pair<int, int> recursion(vector<int> &a, int sum, int index, int plus, int minus, int mult, int div)
{
	int n = a.size();
	if (index == n)
	{
		return make_pair(sum, sum);
	}

	vector<pair<int, int>> arr;
	if (plus != 0)
	{
		arr.push_back(recursion(a, sum + a[index], index + 1, plus - 1, minus, mult, div));
	}
	if (minus != 0)
	{
		arr.push_back(recursion(a, sum - a[index], index + 1, plus, minus - 1, mult, div));
	}
	if (mult != 0)
	{
		arr.push_back(recursion(a, sum * a[index], index + 1, plus, minus, mult - 1, div));
	}
	if (div != 0)
	{
		arr.push_back(recursion(a, sum / a[index], index + 1, plus, minus, mult, div - 1));
	}

	int k = arr.size();

	pair<int, int> ans = arr[0];

	for (int i = 0; i < k; i++)
	{
		if (ans.first < arr[i].first)
			ans.first = arr[i].first;

		if (ans.second > arr[i].second)
			ans.second = arr[i].second;
	}

	return ans;


}



int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> oper(4);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	
	pair<int, int> x = recursion(arr, arr[0], 1, oper[0], oper[1], oper[2], oper[3]);


	cout << x.first << endl << x.second;
}

