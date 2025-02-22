#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	vector<long long> v;
	for (long long i = 0; i < n; i++)
	{
		long long input;
		cin >> input;
		v.push_back(input);
	}
	
	sort(v.begin(), v.end());

	priority_queue<pair<long long, long long>> pq;
	long long count = 0; long long temp = v[0];
	for (long long i = 1; i < n; i++)
	{
		if (temp == v[i])
		{
			count++;
		}
		else
		{
			pq.push({ ++count, -temp });
			temp = v[i];
			count = 0;
		}
	}
	pq.push({ ++count, -temp });

	long long result = -pq.top().second;
	cout << result;
}