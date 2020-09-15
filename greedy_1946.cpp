#include <iostream>

using namespace std;

int main()
{
	int T; // 테스트 케이스의 개수
	int N; // 지원자의 숫자
	
	

	cin >> T;	// 테스트 케이스 입력 받아
	

	for(int k=0;k<T;k++)
	{
		cin >> N;	// 지원자의 숫자 입력 받아
		int ans = 0;
		int temp;
		int num, rank;
		int *score = new int[N + 1]();	// 배열 값 0으로 초기화

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