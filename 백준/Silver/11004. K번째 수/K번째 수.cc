#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long n, k;
	cin >> n >> k;

	vector<long long> v;
	for (long long i = 0; i < n; i++)
	{
		long long input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	cout << v[k - 1];
}