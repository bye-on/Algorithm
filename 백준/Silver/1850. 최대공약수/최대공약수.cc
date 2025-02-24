#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
	while (b > 0)
	{
		long long temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long a, b;
	cin >> a >> b;
	
	
	long long result;
	if (a > b)
		result = gcd(a, b);
	else
		result = gcd(b, a);

	for (long long i = 0; i < result; i++)
	{
		cout << "1";
	}
}