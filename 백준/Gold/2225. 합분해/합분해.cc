#include <iostream>
using namespace std;

long long dp[201][201];
int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i == 1)
				dp[i][j] = j;
			else if (j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[n][k];
}