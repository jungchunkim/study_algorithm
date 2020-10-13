#include <iostream>
#include <vector>

using namespace std;

int sol;

void recursion(vector<int> &a,int sum, int num)
{

	if (num == 2)
	{
		if (sum > sol)
			sol = sum;
		return;
	}
		

	for (int index = 1; index < num - 1; index++)
	{
		int temp;
		// ���� �ִ� ����
		temp = sum + a[index - 1] * a[index + 1];
		//�� ĭ�� ������ ��ܿ��� for�� 
		vector<int> b(num - 1);
		for (int k = 0; k < index; k++)
		{
			b[k] = a[k];
		}
		for (int i = index; i < num-1; i++)
		{
			b[i] = a[i + 1];
		}
		// �ٽ� recursion �Լ�
		recursion(b, temp, num - 1);
	}
}


int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	recursion(arr, 0, n);

	cout << sol;
}