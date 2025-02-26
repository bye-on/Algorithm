#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int j = 0; j < t; j++)
	{
		int a, b;
		cin >> a >> b;

		while (true)
		{
			if (a > b)
			{
				a /= 2;
			}
			else if (a < b)
			{
				b /= 2;
			}
			else
			{
				break;
			}
		}

		if (a > 0)
			cout << a * 10 << '\n';
		else
			cout << 1 * 10 << '\n';
	}
}