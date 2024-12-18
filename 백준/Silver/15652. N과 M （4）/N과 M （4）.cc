#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void repeat_comb(vector<int> arr, vector<int> comb, int r, int index, int depth)
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
	else if (index == arr.size())
		return;

	comb[depth] = arr[index];
	repeat_comb(arr, comb, r - 1, index, depth + 1);
	repeat_comb(arr, comb, r, index + 1, depth);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr;
	vector<int> comb(m);

	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}

	repeat_comb(arr, comb, m, 0, 0);
}