#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	deque<long long> d;
	for (long long i = 0; i < n; i++)
	{
		long long input;
		cin >> input;
		d.push_back(input);
	}
	sort(d.begin(), d.end());

	long long conn = d.front();
	d.pop_front();
	long long cnt = 0;
	while (true)
	{
		if (conn <= 0)
		{
			conn = d.front();
			d.pop_front();
		}
		if (d.empty())
			break;

		if (d.size() > 1)
		{
			long long a = d.back();
			d.pop_back();
			long long b = d.back();
			d.pop_back();

			d.push_back(a + b);
			conn--;
			cnt++;
		}
		else
		{
			// d.pop_front();
			conn = 0;
			cnt++;
		}
	}

	cout << cnt;
}