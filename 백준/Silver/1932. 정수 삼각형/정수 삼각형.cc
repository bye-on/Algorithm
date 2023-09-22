#include <iostream>
using namespace std;
int arr[501][501];
int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][i - 1] + arr[i][i];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	int maxDP = 0;
	for (int i = 1; i <= n; i++) {
		if (maxDP <= dp[n][i]) maxDP = dp[n][i];
	}
	cout << maxDP;
}