#include <iostream>
#include <vector>
using namespace std;

int parent[100001];

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
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int g, p;
	cin >> g >> p;

	for (int i = 1; i <= g; i++)
	{
		parent[i] = i;
	}

	int result = 0;
	for (int i = 1; i <= p; i++)
	{
		int airplane;
		cin >> airplane;
		
		int index = find_parent(airplane);
		if (index == 0) break;

		union_parent(index, index - 1);
		result++;
	}

	cout << result;
}