#include<iostream>

using namespace std;

int main() {
	int L, P, V,i=1;
	int num;
	int remain;
	int sol;

	while (1)
	{
		cin >> L >> P >> V;
		sol = 0;
		if((L == 0) && (P == 0) && (V == 0))
		{
			break;
		}
		else
		{
			num = V / P;
			sol += num * L;
			remain = V % P;
			if (remain <= L)
				sol += remain;
			else
				sol += L;
		}
		cout << "Case " << i << ": " << sol << endl;
		i++;
	}
}