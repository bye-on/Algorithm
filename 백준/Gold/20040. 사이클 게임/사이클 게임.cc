#include <iostream>
#include <vector>
using namespace std;

int parent[500000];

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
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (find_parent(a) != find_parent(b))
			union_parent(a, b);
		else
		{
			cout << i + 1;
			return 0;
		}
	}

	cout << 0;
}