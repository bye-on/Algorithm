#include <iostream>
using namespace std;

long long dp[100001][4];

int main()
{
	dp[1][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i < 100001; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		cout << (dp[input][1] + dp[input][2] + dp[input][3]) % 1000000009 << '\n';
	}
}