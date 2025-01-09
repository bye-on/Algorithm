#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	vector<long long> x;
	vector<long long> y;
	for (long long i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	long long xSum = 0; long long ySum = 0;
	for (long long i = 0; i < n - 1; i++)
	{
		xSum += x[i + 1] * y[i];
		ySum += y[i + 1] * x[i];
	}
	xSum += x[0] * y[n - 1];
	ySum += y[0] * x[n - 1];

	long long result = xSum - ySum;
	printf("%.1lf", abs(result / 2.0));
}