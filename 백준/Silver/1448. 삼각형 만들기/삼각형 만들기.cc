#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	sort(v.rbegin(), v.rend());
	int result = -1;
	for (int i = 0; i < n - 2; i++)
	{
		if (v[i] < (v[i + 1] + v[i + 2]))
			result = max(result, (v[i] + v[i + 1] + v[i + 2]));
	}

	cout << result;
}