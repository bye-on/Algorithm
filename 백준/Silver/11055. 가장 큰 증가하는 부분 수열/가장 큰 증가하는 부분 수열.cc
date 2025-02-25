#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	int maxnum = 0;
	for (int i = 1; i <= n; i++)
	{
		maxnum = max(maxnum, dp[i]);
	}

	cout << maxnum;
}