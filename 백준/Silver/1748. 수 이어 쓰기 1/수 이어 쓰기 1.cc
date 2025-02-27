#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long num[11];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;
	long long length = to_string(n).length();
	
	for (int i = 1; i <= length; i++)
	{
		num[i] = 9 * i * pow(10, i - 1);
	}

	long long result = n - pow(10, length - 1) + 1;
	result *= length;
	for (int i = 1; i < length; i++)
	{
		result += num[i];
	}
	cout << result;
}