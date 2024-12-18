#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void repeat_perm(vector<int>& arr, vector<int> perm, int depth)
{
	if (depth == perm.size())
	{
		for (int i = 0; i < perm.size(); i++)
		{
			cout << perm[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		perm[depth] = arr[i];
		repeat_perm(arr, perm, depth + 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr;
	vector<int> perm(m);

	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}

	repeat_perm(arr, perm, 0);
}