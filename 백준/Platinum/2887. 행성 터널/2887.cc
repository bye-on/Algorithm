#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int parent[100001];
vector<pair<int, int>> vx;
vector<pair<int, int>> vy;
vector<pair<int, int>> vz;

int find_parent(int parent[], int x)
{
	if (parent[x] != x)
		parent[x] = find_parent(parent, parent[x]);
	return parent[x];
}

void union_parent(int parent[], int a, int b)
{
	a = find_parent(parent, a);
	b = find_parent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		vx.push_back(make_pair(x, i));
		vy.push_back(make_pair(y, i));
		vz.push_back(make_pair(z, i));
	}

	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vz.begin(), vz.end());

	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n - 1; i++)
	{
		pq.push({ -abs(vx[i].first - vx[i + 1].first), {vx[i].second, vx[i + 1].second } });
		pq.push({ -abs(vy[i].first - vy[i + 1].first), {vy[i].second, vy[i + 1].second } });
		pq.push({ -abs(vz[i].first - vz[i + 1].first), {vz[i].second, vz[i + 1].second } });
	}

	int result = 0;
	while (!pq.empty()) 
	{
		int cost = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		if (find_parent(parent, a) != find_parent(parent, b))
		{
			union_parent(parent, a, b);
			result += cost;

			//cout << a << " " << b << " " << cost << '\n';
		}
	}
	cout << result;
}