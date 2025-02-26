#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string str; int n;
	cin >> str >> n;

	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[str.length() - 1 - i] >= 'A' && str[str.length() - 1 - i] <= 'Z')
		{
			int num = str[str.length() - 1 - i] - 'A' + 10;
			int temp = pow(n, i);
			result += (num * temp);
		}
		else
		{
			int num = str[str.length() - 1 - i] - '0';
			int temp = pow(n, i);
			result += (num * temp);
		}
	}

	cout << result;
}