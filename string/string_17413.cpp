#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	bool print_str = false;
	getline(cin, s);
	string temp = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{	
			if (print_str)
			{// <> ���̿� ���� �� 
				cout << s[i];
			}
			else
			{
				//temp �Ųٷ� ���
				for (int j = 0; j < temp.length(); j++)
				{
					cout << temp[temp.length() - 1 - j];
				}
				cout << s[i];
				temp.clear();
			}	
		}
		else if (s[i] == '<')
		{
			//temp �Ųٷ� ���
			for (int j = 0; j < temp.length(); j++)
			{
				cout << temp[temp.length() - 1 - j];
			}
			cout << s[i];
			temp.clear();
			print_str = true;
		}
		else if (s[i] == '>')
		{
			cout << s[i];
			print_str = false;
		}
		else
		{
			if (print_str)
			{// <> ���̿� ���� �� 
				cout << s[i];
			}
			else
			{
				temp += s[i];
			}
		}
	}
	for (int j = 0; j < temp.length(); j++)
	{
		cout << temp[temp.length() - 1 - j];
	}



}