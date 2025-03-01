#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { -1,0,1,-1,1, -1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

int n, m;
int map[51][51];
bool visited[51][51];
queue<pair<int, int>> q;

bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = true;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (!visited[nx][ny] && map[nx][ny] == 0)
			{
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx,ny });
			}
		}

		if (check()) return;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
			if (input == 1)
				q.push({ i,j });
		}
	}

	bfs();

	int maxnum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			maxnum = max(maxnum, map[i][j]);
		}
	}

	cout << maxnum - 1;
}