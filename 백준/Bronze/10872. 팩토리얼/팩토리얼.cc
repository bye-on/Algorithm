#include <iostream>
using namespace std;

int fact[15];
int factorial(int n)
{
	if (n <= 1)
		return fact[n] = 1;
	
	if (fact[n - 1] != 0)
		return fact[n] = fact[n - 1] * n;
	else
		return fact[n] = n * factorial(n - 1);
}

int main()
{
	int n;
	cin >> n;

	factorial(n);
	cout << fact[n];
}