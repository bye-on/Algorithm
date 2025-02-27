#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b;
vector<int> graph[101];
bool visited[101];

int result = -1;

void dfs(int x, int depth)
{
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int next = graph[x][i];
		if (next == a)
			result = max(result, depth + 1);

		if(!visited[next])
			dfs(next, depth + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	cin >> a >> b;

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(b, 0);
	cout << result;
}