#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long> v;
	for (long i = 0; i < n; i++)
	{
		long input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	cout << v[0] * v[v.size() - 1];
}