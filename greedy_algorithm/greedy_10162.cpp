#include <iostream>

using namespace std;

int main()
{
	int T; // �丮�ð�
	int num_A, num_B, num_C;

	cin >> T; // �丮�ð��� �Է¹޴´�



	if (T % 10 != 0)
	{
		cout << -1;
	}
	else
	{
		num_A = T / 300;
		num_B = (T - (num_A * 300))/60;
		num_C = (T - (num_A * 300 + num_B * 60)) / 10;

		cout << num_A << num_B << num_C;
	}


}