#include <iostream>
#include <cmath>
using namespace std;

long long n;

long long binary_search()
{
	long long start = 1; long long end = sqrt(2 * n);

	while (start <= end)
	{
		long long middle = start + (end - start) / 2;
		long long level = ((middle * (middle + 1)) / 2);

		if (n > level)
			start = middle + 1;
		else if (n < level)
			end = middle - 1;
		else
			return middle;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		cin >> n;
		cout << "#" << t << " " << binary_search() << '\n';
	}

	return 0;
}