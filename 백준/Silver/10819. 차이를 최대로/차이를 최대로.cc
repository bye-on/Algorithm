#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxnum = 0;

void permutation(vector<int>& v, int depth, int n, int r)
{
	if (depth == r)
	{
		int temp = 0;
		for (int i = 0; i < r - 1; i++)
		{
			temp += abs(v[i] - v[i + 1]);
		}
		maxnum = max(maxnum, temp);
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(v[depth], v[i]);
		permutation(v, depth + 1, n, r);
		swap(v[depth], v[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	permutation(v, 0, v.size(), n);
	cout << maxnum;
}