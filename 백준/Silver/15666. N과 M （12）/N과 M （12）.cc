#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void repeat_comb(vector<int>& arr, vector<int>& comb, int r, int index, int depth)
{
	if (r == depth)
	{
		for (int i = 0; i < comb.size(); i++)
		{
			cout << comb[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (index == arr.size())
		return;

	comb[depth] = arr[index];
	repeat_comb(arr, comb, r, index, depth + 1);
	repeat_comb(arr, comb, r, index + 1, depth);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v;
	vector<int> comb(m);

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	repeat_comb(v, comb, m, 0, 0);
}