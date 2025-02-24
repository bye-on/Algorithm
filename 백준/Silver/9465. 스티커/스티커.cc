#include <iostream>
#include <algorithm>
using namespace std;

int sticker[2][100001];
int dp[2][100001];
int main()
{
	int t;
	cin >> t;
	
	for (int c = 0; c < t; c++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int input;
				cin >> input;
				sticker[i][j] = input;
			}
		}

		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		int result = max(dp[0][n], dp[1][n]);
		cout << result << '\n';
	}
}