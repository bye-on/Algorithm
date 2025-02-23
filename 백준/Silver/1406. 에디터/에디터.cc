#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<char> left; stack<char> right;
	string str; int n;
	cin >> str >> n;

	for (int i = 0; i < str.length(); i++)
	{
		left.push(str[i]);
	}

	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		int cursor = left.size();

		if (c == 'L')
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}
		if (c == 'D')
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}
		if (c == 'B')
		{
			if (!left.empty())
				left.pop();
		}
		if (c == 'P')
		{
			char t;
			cin >> t;

			left.push(t);
		}
	}
	
	string result;

	while (!right.empty())
	{
		left.push(right.top());
		right.pop();
	}

	while (!left.empty())
	{
		result += left.top();
		left.pop();
	}

	reverse(result.begin(), result.end()); 

	cout << result;
}