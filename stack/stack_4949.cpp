#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	
	while (1)
	{
		stack<char> arr;
		getline(cin, s);

		if (s[0] == '.')
		{
			break;
		}
		else
		{
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == '(')
				{
					arr.push(s[i]);
				}
				else if (s[i] == '[')
				{
					arr.push(s[i]);
				}
				else if (s[i] == ')')
				{
					if (arr.empty())
					{
						arr.push(s[i]);
						break;
					}
					else
					{
						if (arr.top() == '(')
						{
							arr.pop();
						}
						else
						{
							break;
						}
					}
					
				}
				else if (s[i] == ']')
				{
					if (arr.empty())
					{
						arr.push(s[i]);
						break;
					}
					else
					{
						if (arr.top() == '[')
						{
							arr.pop();
						}
						else
						{
							break;
						}
					}
				}
			}

			if (arr.empty())
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
		
	}
	
}