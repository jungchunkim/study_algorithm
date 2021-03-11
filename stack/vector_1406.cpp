#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	string b;
	vector<char> arr;
	int M;

	cin >> s;

	cin >> M;

	for (int i = 0; i < s.length(); i++)
	{
		arr.push_back(s[i]);
	}

	cin.ignore(); //버퍼를 비워주자
	int index = s.size();

	for (int j = 0; j < M; j++)
	{
		getline(cin, b);

		if (b.size() > 1)
		{
			arr.insert(arr.begin() + index, b[2]);
			index++;
		}
		else
		{
			if (b[0] == 'L')
			{
				if (index != 0)
				{
					index--;
				}
			}
			else if (b[0] == 'D')
			{
				if (index != arr.size())
					index++;
			}
			else
			{// 'B' 일때
				if (index != 0)
				{
					arr.erase(arr.begin() + (index - 1));
					index--;
				}
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}


}