#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	queue<int> brr;
	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		brr.push(i);
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < K; j++)
		{
			brr.push(brr.front());
			brr.pop();
		}
		if (i == N - 1)
		{
			cout << brr.front();
		}
		else
		{
			cout << brr.front() << ", ";
		}
		
		brr.pop();
	}
	cout << ">";

}