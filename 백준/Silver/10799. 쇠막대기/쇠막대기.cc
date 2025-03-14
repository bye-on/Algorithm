#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;

	stack<char> s;
	int cnt = 0;
	char bef;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c == '(' || s.empty())
		{
			s.push(c);
			bef = c;
		}
		else if (c == ')')
		{
			if (bef == '(')
			{
				s.pop();
				cnt += s.size();
				bef = c;
			}
			else if (bef == ')')
			{
				s.pop();
				cnt++;
				bef = c;
			}
		}
	}

	cout << cnt;
}