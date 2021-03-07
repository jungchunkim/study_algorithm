#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a[26];	//알파벳을 받을 배열 (26가지 !!)
	string s;
	int N, count = 0;
	int index;
	int index_prev = -1;
	cin >> N;
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			a[j] = 0;
		}
		cin >> s;
		bool in_str = false;
		for (int j = 0; j < s.size(); j++)
		{
			index = s[j] - 'a';

			if (a[index] == 1 && index_prev!=index)
			{
				in_str = true;
				break;
			}
			else
			{
				a[index] = 1;
			}
			index_prev = index;
		}
		if (in_str==false)
		{
			count++;
		}
	}
	cout << count;

}