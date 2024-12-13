#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int binary_search(int start, int end, int target)
{
	while (start <= end)
	{
		int middle = (start + end) / 2;

		if (target < v[middle])
			end = middle - 1;
		else if (target > v[middle])
			start = middle + 1;
		else return middle;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int m;
	cin >> m;
	vector<int> result;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;

		if (binary_search(0, v.size() - 1, input) == -1)
			result.push_back(0);
		else
			result.push_back(1);
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}