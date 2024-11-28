#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main()
{
	int n, r;
	cin >> n >> r;

	vector<int> v;
	vector<int> visited(n);

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	sort(v.begin(), v.end());

	do
	{
		for (int i = 0; i < r; i++)
			cout << v[i] << " ";
		cout << '\n';
		reverse(v.begin() + r, v.end());
	} while (next_permutation(v.begin(), v.end()));
}
