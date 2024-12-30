#include <iostream>
#include <vector>
using namespace std;

int dp[101][100001]; // 물품, 무게
int main()
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> v(n + 1);
	for (int i = 0; i < n; i++)
	{
		int w, k;
		cin >> w >> k;
		v[i + 1] = { w,k }; // 무게, 가치
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 0; // 무게 0일 땐 가치 0
	}

	for (int i = 1; i <= n; i++) // 물건
	{
		for (int j = 1; j <= k; j++) // 남은 무게
		{
			if (v[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], v[i].second + dp[i - 1][j - v[i].first]);
		}
	}

	cout << dp[n][k];
}