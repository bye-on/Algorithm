#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;

	stack<char> s;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c == '(' || s.empty())
		{
			s.push(c);
		}
		else if (c == ')')
		{
			if (str[i-1] == '(')
			{
				s.pop();
				cnt += s.size();
			}
			else if (str[i-1] == ')')
			{
				s.pop();
				cnt++;
			}
		}
	}

	cout << cnt;
}