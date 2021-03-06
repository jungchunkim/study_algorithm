#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	string s;
	int num;
	string s1;

	cin >> T;

	for (int i = 0; i < T; i++)
	{

		cin >> s;
		cin >> num; // 배열의 개수
		cin >> s1;
		string s2="";
		deque<int> arr;

		for (int j = 0; j < s1.size(); j++)
		{
			if (s1[j] == '[')
			{
				continue;
			}
			else if ((s1[j]-'0') >= 0 && (s1[j] - '0')<=9)
			{
				s2 += s1[j];
			}
			else if (s1[j] == ',' || s1[j] == ']')
			{
				if (s2.empty())
				{
					break;
				}
				else 
				{
					int n = atoi(s2.c_str());
					arr.push_back(n);
					s2.clear();
				}
				
			}
		}
		

		int index = 0;
		int t_f = 1;

		for (int k = 0; k < s.size(); k++)
		{
			if (s[k] == 'D')
			{
				if (arr.empty())
				{
					cout << "error" << "\n";
					t_f = 0;
					break;
				}
				else
				{
					if (index == 0)
					{
						arr.pop_front();
					}
					else
					{
						arr.pop_back();
					}
				}
				
			}
			else
			{// R인 경우
				if (index == 0)
				{
					index = arr.size();
				}
				else
				{
					index = 0;
				}
			}

		}	
		if (t_f==1)
		{
			if (index == 0)
			{// 앞에서 부터 출력
				cout << '[';
				for (int m = 0; m < arr.size(); m++)
				{
					if (m != (arr.size() - 1))
						cout << arr[m] << ',';
					else
						cout << arr[m];
				}
				cout << ']'<<'\n';
			}
			else
			{// 뒤에서 부터 출력
				cout << '[';
				for (int m = arr.size() - 1; m >= 0; m--)
				{
					if (m != 0)
						cout << arr[m] << ',';
					else
						cout << arr[m];
				}
				cout << ']'<<'\n';
			}
		}
	}
	
}