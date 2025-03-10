#include <iostream>
using namespace std;

long long calc(int num, int x)
{
	int cnt = 0;

	for (long long i = x; num / i >= 1; i *= x)
	{
		cnt += num / i;
	}
	
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	long long two = calc(a, 2) - calc(b, 2) - calc(a - b, 2);
	long long five = calc(a, 5) - calc(b, 5) - calc(a - b, 5);
	
	long long total = min(two, five);
	cout << total;
}