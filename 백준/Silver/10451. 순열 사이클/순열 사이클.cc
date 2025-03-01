#include <iostream>
using namespace std;

int parent[1001];

int find_parent(int x)
{
	if (parent[x] != x)
		return parent[x] = find_parent(parent[x]);
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
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int input;
			cin >> input;

			if (find_parent(i) != find_parent(input))
				union_parent(i, input);
			else
				cnt++;
		}

		cout << cnt << '\n';
	}
}