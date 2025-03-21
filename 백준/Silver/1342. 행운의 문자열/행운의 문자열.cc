#include <iostream>
#include <vector>
using namespace std;

string str;
int cnt = 0;

bool check(vector<char> &s)
{
	char c = s[0];
	for (int i = 1; i < str.size(); i++)
	{
		if (c == s[i])
			return false;

		c = s[i];
	}

	return true;
}

void dfs(vector<int> &alpha, vector<char> &ret, int depth)
{
	if (depth == str.length())
	{
		if (check(ret))
			cnt++;
		return;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 0)
		{
			char c = i + 'a';
			if (ret[depth - 1] != c)
			{
				alpha[i]--;
				ret[depth] = c;
				dfs(alpha, ret, depth + 1);
				alpha[i]++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	vector<int> alpha(26);
	for (int i = 0; i < str.length(); i++)
	{
		int num = str[i] - 'a';
		alpha[num]++;
	}

	vector<char> ret(11);
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 0)
		{
			alpha[i]--;
			ret[0] = i + 'a';
			dfs(alpha, ret, 1);
			alpha[i]++;
		}
	}

	cout << cnt;
}