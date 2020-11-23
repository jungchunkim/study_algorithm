#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{//�߰���-1�� �������� 
			end = mid - 1;
		}
		else
		{//�߰��� +1�� ����������
			start = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int n, target;
	cin >> n >> target;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int sol = binarySearch(arr, target, 0, n - 1);
	if (sol == -1)
	{
		cout<< "���� ���մϴ�.";
	}
	else
	{
		cout << sol + 1 << "��° �����մϴ�";
	}
}