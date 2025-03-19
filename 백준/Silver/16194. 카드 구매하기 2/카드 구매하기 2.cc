#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1e9;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	dp[1] = v[1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + v[j]);
		}
	}

	cout << dp[n];
}