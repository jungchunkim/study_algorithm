#include <iostream>

using namespace std;

int main()
{
	int T; // �׽�Ʈ ���̽��� ����
	int N; // �������� ����
	
	

	cin >> T;	// �׽�Ʈ ���̽� �Է� �޾�
	

	for(int k=0;k<T;k++)
	{
		cin >> N;	// �������� ���� �Է� �޾�
		int ans = 0;
		int temp;
		int num, rank;
		int *score = new int[N + 1]();	// �迭 �� 0���� �ʱ�ȭ

		for (int i = 0; i < N; i++)
		{
			cin >> num >> rank;
			score[rank] = num;
		}

		temp = score[1];
		ans++;

		for (int i = 1; i <= N; i++)
		{
			if (temp > score[i])
			{
				temp = score[i];
				ans++;
			}
		}
		cout << ans << '\n';
	}
	
	
	
}