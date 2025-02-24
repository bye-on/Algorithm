#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	while (b > 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		int result = a * b;
		
		if (a > b)
			cout << result / gcd(a, b) << '\n';
		else
			cout << result / gcd(b, a) << '\n';
	}
}