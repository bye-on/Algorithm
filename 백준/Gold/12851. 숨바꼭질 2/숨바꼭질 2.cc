#include <iostream>
#include <queue>
using namespace std;

int n, k;
int path[100001];
int cnt = 0;
int INF = 1e9;

int main()
{
	cin >> n >> k;
	queue<int> q;

	for (int i = 0; i < 100001; i++)
	{
		path[i] = INF;
	}

	path[n] = 0;
	q.push(n);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == k)
			cnt++;

		int next = current * 2;
		if (next < 100001 && path[next] >= path[current] + 1)
		{
			path[next] = path[current] + 1;
			q.push(next);
		}

		next = current - 1;
		if (next >= 0 && path[next] >= path[current] + 1)
		{
			path[next] = path[current] + 1;
			q.push(next);
		}
		next = current + 1;
		if (next < 100001 && path[next] >= path[current] + 1)
		{
			path[next] = path[current] + 1;
			q.push(next);
		}
	}

	cout << path[k] << '\n' << cnt;
}