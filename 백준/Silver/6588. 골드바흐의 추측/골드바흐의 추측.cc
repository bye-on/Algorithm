#include <iostream>
#include <vector>
using namespace std;

bool isPrime[1000001];
void prime()
{
	for (int i = 2; i * i < 1000001; i++)
	{
		if (isPrime[i]) continue;

		for (int j = i + i; j < 1000001; j += i)
		{
			isPrime[j] = true;
		}
	}
}

bool goldbach(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (!isPrime[i])
		{
			int temp = n - i;
			if (!isPrime[temp])
			{
				cout << n << " = " << i << " + " << temp << '\n';
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	prime();

	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		if (!goldbach(n))
			cout << "Goldbach's conjecture is wrong.\n";
	}
}