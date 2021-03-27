#include <iostream>

using namespace std;

int main()
{
	int coin[] = { 500,100,50,10,5,1 };
	int price;
	cin >> price;

	int rec_price = 1000 - price;

	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		count += rec_price / coin[i];
		rec_price = rec_price % coin[i];
	}

	cout << count;
}