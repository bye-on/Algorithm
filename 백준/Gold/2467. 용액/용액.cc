#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long INF = 1e9 * 2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long n;
	cin >> n;

	vector<long long> v;
	for (long long i = 0; i < n; i++)
	{
		long long input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	long long minNum = INF;
	long long start = 0;
	long long end = n - 1;
	long long a, b;

	while (start < end)
	{
		long long temp = v[start] + v[end];
		if (abs(temp) < minNum)
		{
			minNum = abs(temp);
			a = start;
			b = end;

			if (minNum == 0)
				break;
		}
		
		if (temp < 0)
			start++;
		else
			end--;
	}

	cout << v[a] << " " << v[b];
}