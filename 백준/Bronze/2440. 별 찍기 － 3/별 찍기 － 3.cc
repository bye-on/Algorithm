#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = n; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			cout << "*";
		}
		cout << '\n';
	}
}