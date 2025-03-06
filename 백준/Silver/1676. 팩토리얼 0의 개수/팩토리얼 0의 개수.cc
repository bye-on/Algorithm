#include <iostream>
using namespace std;

long long fact[501];

void factorial(int n)
{
	for (int i = 2; i <= n; i++)
	{
		fact[i] = fact[i - 1];
		
		int num = i;
		while (num % 5 == 0)
		{
			fact[i]++;
			num /= 5;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	factorial(n);
	cout << fact[n];
}