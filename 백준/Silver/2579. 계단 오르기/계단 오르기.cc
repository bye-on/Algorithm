#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
int main()
{
	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		v[i] = input;
	}

	dp[1] = v[1];
	dp[2] = dp[1] + v[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = v[i] + max(v[i - 1] + dp[i - 3], dp[i - 2]);
	}

	cout << dp[n];
}