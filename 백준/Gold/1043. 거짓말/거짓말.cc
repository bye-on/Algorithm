#include <iostream>
#include <vector>
using namespace std;

int parent[51];
vector<int> v[50];

int find_parent(int x)
{
	if (parent[x] == x)
		return parent[x];

	return find_parent(parent[x]);
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

	int truth;
	cin >> truth;
	for (int i = 0; i < truth; i++)
	{
		int input;
		cin >> input;
		parent[input] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int party;
		cin >> party;

		for (int j = 0; j < party; j++)
		{
			int input;
			cin >> input;
			v[i].push_back(input);
		}

		for (int j = 0; j < v[i].size() - 1; j++)
		{
			union_parent(v[i][j], v[i][j + 1]);
		}
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		bool know = false;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (find_parent(v[i][j]) == 0)
			{
				know = true;
				break;
			}
		}

		if (!know)
			count++;
	}

	cout << count;
}