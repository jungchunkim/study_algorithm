#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> word;
int num[26];
int result = 0;


int main()
{
	int N;	//�ܾ��� ����
	string str;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// ���ڿ� 2���� �Է¹޴´�.
		cin >> str;
		word.push_back(str);
	}

	for (int i = 0; i < word.size(); i++)
	{
		int k = 1;
		for (int j = word[i].size()-1; j>=0 ; j--)
		{
			int val = word[i][j] - 'A';
			num[val] += k;
			k *= 10;
		}

	}

	sort(num, num + 26);

	int alt = 9;
	for (int i = 25; i >= 0; i--)
	{
		if (num[i] == 0)
			break;
		result += num[i] * alt;
		alt--;

	}

	cout << result;
}