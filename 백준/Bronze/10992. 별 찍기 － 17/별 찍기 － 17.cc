#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((n - 1 - i) == j)
				cout << "*";
			else
				cout << " ";
		}

		for (int j = 0; j < i; j++)
		{
			if ((i - 1) == j)
				cout << "*";
			else
				cout << " ";
		}
		
		cout << '\n';
	}

	for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << "*";
	}
}