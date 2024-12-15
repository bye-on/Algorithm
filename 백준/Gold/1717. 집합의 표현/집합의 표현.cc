#include <iostream>
#include <vector>
using namespace std;

int parent[1000001];

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
	
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	vector<string> v;
	for (int i = 0; i < m; i++)
	{
		int calc;
		cin >> calc;

		if (calc == 0)
		{
			int a, b;
			cin >> a >> b;

			union_parent(a, b);
		}
		if (calc == 1)
		{
			int a, b;
			cin >> a >> b;
			if (find_parent(a) == find_parent(b))
				v.push_back("YES");
			else
				v.push_back("NO");
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}