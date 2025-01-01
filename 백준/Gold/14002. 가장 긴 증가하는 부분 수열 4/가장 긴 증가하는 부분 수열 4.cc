#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> lis, int start, int end, int target)
{
	while (start < end)
	{
		int middle = (start + end) / 2;

		if (lis[middle] < target)
			start = middle + 1;
		else
			end = middle;
	}
	return end;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	vector<int> lis;
	vector<int> path;
	lis.push_back(v[0]);
	path.push_back(0);

	for (int i = 1; i < n; i++)
	{
		if (v[i] > lis.back())
		{
			lis.push_back(v[i]);
			path.push_back(lis.size() - 1);
		}
		else
		{
			int pos = binary_search(lis, 0, lis.size() - 1, v[i]);
			path.push_back(pos);
			lis[pos] = v[i];
		}

	}

	vector<int> result;
	int length = lis.size() - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (path[i] == length)
		{
			result.push_back(v[i]);
			length--;
		}
	}

	cout << lis.size() << '\n';
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}