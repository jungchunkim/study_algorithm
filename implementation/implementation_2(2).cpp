#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//�ð� ����
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int count = 0;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if (k / 10 == 3 || k % 10 == 3 || j / 10 == 3 || j % 10 == 3 || i % 10 == 3)
				{
					count++;
				}
			}
		}
	}
	


	cout << count;
}