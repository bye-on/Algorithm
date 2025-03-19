#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(abs(s - input));
	}

	int maxnum = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (maxnum < v[i]) maxnum = gcd(v[i], maxnum);
		else maxnum = gcd(maxnum, v[i]);
	}

	cout << maxnum;
}