#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	long long n;
	while (cin >> n)
	{
		int ans = 1;
		int k = 1;
		while (true)
		{
			if (ans % n == 0)
			{
				cout << k << '\n';
				break;
			}

			ans = ans * 10 + 1;
			ans %= n;
			k++;
		}
	}
}