#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 1e9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, s;
	cin >> n >> s;
	vector<long long> v;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	int result = INF;
	int sum = 0; int end = 0;
	for (int start = 0; start < n; start++)
	{
		while (sum < s && end < n)
		{
			sum += v[end];
			end++;
		}

		if (sum >= s)
			result = min(result, end - start);

		sum -= v[start];
	}

	if (result == INF)
		cout << 0;
	else
		cout << result;
}