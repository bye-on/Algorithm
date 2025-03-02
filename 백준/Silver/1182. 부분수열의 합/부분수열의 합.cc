#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int cnt = 0;

void combination(vector<int>& v, vector<int>& comb, int depth, int n, int r, int index)
{
	if (r == 0)
	{
		int result = 0;
		for (int i = 0; i < comb.size(); i++)
		{
			result += comb[i];
		}

		if (result == S)
			cnt++;
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

	cin >> N >> S;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++)
	{
		vector<int> comb(i);
		combination(v, comb, 0, N, i, 0);
	}

	cout << cnt;
}