#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{

	cin.tie(NULL);  
	ios_base::sync_with_stdio(false);

	int N, M;
	int count = 0;
	cin >> N >> M;
	vector<string> arr;
	vector<string> brr;
	string a;

	for (int i = 0; i < N + M; i++)
	{
		cin >> a;
		arr.push_back(a);

	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < N + M; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			brr.push_back(arr[i]);
		}
	}
	
	cout << brr.size() << "\n";

	for (int i = 0; i < brr.size(); i++)
	{
		cout << brr[i] << "\n";
	}
}