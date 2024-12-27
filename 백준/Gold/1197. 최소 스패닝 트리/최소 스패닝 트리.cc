#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[10001];
priority_queue<pair<long long, pair<int, int>>> pq;
int find_parent(int x)
{
	if (parent[x] != x)
		parent[x] = find_parent(parent[x]);

	return parent[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main()
{
	int v, e;
	cin >> v >> e;

	for (int i = 0; i <= v; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c, {a,b} });
	}

	long long weight = 0;
	while (!pq.empty())
	{
		long long count = -pq.top().first;

		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		if (find_parent(a) != find_parent(b))
		{
			union_parent(a, b);
			weight += count;
		}
	}

	cout << weight;
}