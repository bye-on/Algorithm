#include <iostream>
using namespace std;

int n, m;
bool visited[1001][1001];
bool done[1001][1001];
char map[1001][1001];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int cnt = 0;

void dfs(int x, int y)
{
	visited[x][y] = true;

	int dir;

	if (map[x][y] == 'U')
		dir = 0;
	else if (map[x][y] == 'D')
		dir = 1;
	else if (map[x][y] == 'L')
		dir = 2;
	else if (map[x][y] == 'R')
		dir = 3;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;

	if (!visited[nx][ny])
	{
		dfs(nx, ny);
	}
	else if(!done[nx][ny])
	{
		cnt++;
	}

	done[x][y] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
				dfs(i, j);
		}
	}

	cout << cnt;
}