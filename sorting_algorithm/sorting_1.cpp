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
	//������ �Ʒ���
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
	// �׳� sort �ϰ� reverse �ص� �ȴ�.
	for (int i = 0; i < N; i++)
	{
		cout << arr[i]<<" ";
	}

}