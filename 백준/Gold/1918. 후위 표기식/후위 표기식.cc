#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> m = { {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1} , {'(', -1}, {')', -1} };

string postfix(string str)
{
	stack<char> s;
	string result;

	for (int i = 0; i < str.length(); i++)
	{
		int temp = str[i] - 'A';

		if (temp >= 0 && temp < 26) // 피연산자
		{
			result += str[i];
		}
		else // 연산자
		{
			if (s.empty()) s.push(str[i]);
			else if (m[s.top()] < m[str[i]]) s.push(str[i]);
			else if (str[i] == '(') s.push(str[i]);
			else
			{
				if (str[i] == ')')
				{
					while (!s.empty())
					{
						if (s.top() == '(')
						{
							s.pop();
							break;
						}
						result += s.top();
						s.pop();
					}
				}
				else
				{
					while (!s.empty())
					{
						if (m[s.top()] < m[str[i]])
						{
							break;
						}
						result += s.top();
						s.pop();
					}
					s.push(str[i]);
				}
			}
		}
	}

	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}

	return result;
}

int main()
{
	string str;
	cin >> str;

	cout << postfix(str);
}