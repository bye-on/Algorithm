#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, m;
int map[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

int bfs(int x, int y)
{
	stack<pair<int, int>> s;
	queue<pair<int, int>> temp;
	temp.push({ x,y });

	while (!temp.empty())
	{
		x = temp.front().first;
		y = temp.front().second;
		temp.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!visited[nx][ny] && map[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				s.push({ nx, ny });
				temp.push({ nx, ny });
			}
		}
	}

	return s.size();
}

int main()
{
	cin >> n >> m;
	int t; cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a - 1][b - 1] = 1;
		q.push({ a - 1, b - 1 });
	}

	int maxnum = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int tmp = bfs(x, y);
		maxnum = max(maxnum, tmp);
	}

	cout << maxnum;
}