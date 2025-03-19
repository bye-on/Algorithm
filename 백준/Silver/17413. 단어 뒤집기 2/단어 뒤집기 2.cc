#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	stack<char> s;
	for (int i = 0; i < str.length();)
	{
		if (str[i] == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}

			while (str[i] != '>')
			{
				cout << str[i++];
			}
			cout << ">";
			i++;
		}
		else if (str[i] != ' ')
		{
			s.push(str[i++]);
		}
		else
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << " ";
			i++;
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}