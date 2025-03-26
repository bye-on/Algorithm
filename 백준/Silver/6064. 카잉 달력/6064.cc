#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m, x, y;
		cin >> n >> m >> x >> y;

		int k;

		if (n > m)
			k = (n * m) / gcd(n, m);
		else
			k = (n * m) / gcd(m, n);

		//if(n == x && m == y)

		int cnt;
		int num1, num2;
		if (n >= y)
		{
			num1 = y;
			num2 = y;
			cnt = y;
		}
		else
		{
			num1 = y % n;
			num2 = y;
			cnt = y;
		}

		bool ok = false;
		for (int i = cnt; i <= k; i = cnt)
		{
			if (num1 == x && num2 == y)
			{
				ok = true;
				break;
			}

			if (num1 == (x % n))
			{
				ok = true;
				break;
			}

			num1 = (num1 + m) % n;
			cnt += m;
		}

		if (ok)
			cout << cnt << '\n';
		else
			cout << -1 << '\n';
	}
}