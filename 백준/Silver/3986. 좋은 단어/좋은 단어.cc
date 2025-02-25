#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		stack<char> s;
		for (int i = 0; i < str.length(); i++)
		{
			if (s.empty())
			{
				s.push(str[i]);
			}
			else
			{
				if (s.top() == str[i])
					s.pop();
				else
					s.push(str[i]);
			}
		}

		if (s.empty())
			result++;
	}
	cout << result;
}