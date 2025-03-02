#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combination(vector<int>& v, vector<int>& comb, int depth, int n, int r, int index)
{
	if (r == 0)
	{
		for (int i = 0; i < comb.size(); i++)
		{
			cout << comb[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (depth == n)
		return;

	comb[index] = v[depth];
	combination(v, comb, depth + 1, n, r - 1, index + 1);
	combination(v, comb, depth + 1, n, r, index);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (true)
	{
		int k;
		cin >> k;
		if (k == 0) break;

		vector<int> v;
		for (int i = 0; i < k; i++)
		{
			int input;
			cin >> input;
			v.push_back(input);
		}

		vector<int> comb(6);
		combination(v, comb, 0, v.size(), 6, 0);
		cout << '\n';
	}
}