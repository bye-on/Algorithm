#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		
		vector<long long> v;
		for (int i = 0; i < n; i++)
		{
			long long input;
			cin >> input;
			v.push_back(input);
		}

		long long result = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[i] < v[j])
					result += gcd(v[j], v[i]);
				else
					result += gcd(v[i], v[j]);
			}
		}

		cout << result << '\n';
	}
}