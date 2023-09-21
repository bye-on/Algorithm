#include <iostream>
using namespace std;
int wine[10001];
int dp[10001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		wine[i] = input;
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]), dp[i - 1]);
	}

	cout << dp[n];
}