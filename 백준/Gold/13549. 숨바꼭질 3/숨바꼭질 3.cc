#include <iostream>
#include <deque>
using namespace std;

int n, k;
int path[100001];
int INF = 1e9;

int main()
{
	cin >> n >> k;
	deque<int> d;

	for (int i = 0; i < 100001; i++)
	{
		path[i] = INF;
	}

	path[n] = 0;
	d.push_front(n);

	while (!d.empty())
	{
		int current = d.front();
		d.pop_front();

		if (current == k)
		{
			cout << path[k];
			break;
		}

		int next = current * 2;
		if (next < 100001 && path[next] > path[current] + 1)
		{
			path[next] = path[current];
			d.push_front(next);
		}

		next = current - 1;
		if (next >= 0 && path[next] > path[current] + 1)
		{
			path[next] = path[current] + 1;
			d.push_back(next);
		}
		next = current + 1;
		if (next < 100001 && path[next] > path[current] + 1)
		{
			path[next] = path[current] + 1;
			d.push_back(next);
		}
	}
}