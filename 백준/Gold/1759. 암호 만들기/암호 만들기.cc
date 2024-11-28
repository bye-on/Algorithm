#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void CheckComb(vector<char> &comb)
{
	int vowel = 0; int consonent = 0;
	for (int i = 0; i < comb.size(); i++)
	{
		if (comb[i] == 'a' || comb[i] == 'e' || comb[i] == 'i' || comb[i] == 'o' || comb[i] == 'u')
			vowel++;
		else
			consonent++;
	}

	if (vowel > 0 && consonent > 1)
	{
		for (int i = 0; i < comb.size(); i++)
		{
			cout << comb[i];
		}
		cout << '\n';
	}
}

int main()
{
	int r, n;
	cin >> r >> n;

	vector<char> v;
	vector<char> comb(r);
	vector<bool> visited(n);

	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < r; i++)
	{
		visited[i] = true;
	}

	do
	{
		comb.clear();
		for (int i = 0; i < v.size(); i++)
		{
			if (visited[i])
				comb.push_back(v[i]);
		}
		CheckComb(comb);
	} while (prev_permutation(visited.begin(), visited.end()));
	
}
