#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B, C;
		cin >> A >> B;
		
		if (A < B)
		{
			C = A;
			A = B;
			B = C;
		}
		

		int new_A = A;
		int new_B = B;
		while (1)
		{
			C = new_A % new_B;
			if (C == 0)
				break;
			new_A = new_B;
			new_B = C;
		}

		cout << A * B / new_B << "\n";
	}

}