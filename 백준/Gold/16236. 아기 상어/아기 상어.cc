#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int N; int minDist;
int shark = 2;  
int feed = 0; int result = 0;
int sharkX, sharkY;
int map[21][21];
int visited[21][21];
int INF = 1e9;

void bfs(int x, int y) // 최단 거리를 계산하는 함수
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;
	visited[x][y] = 0;
	q.push({ x,y });

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (visited[nx][ny] == -1 && map[nx][ny] <= shark)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

bool find() // 현재 상어 위치에서 최단 거리 물고기 찾기
{
	minDist = INF;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] != -1 && map[i][j] >= 1 && map[i][j] < shark)
			{
				if (visited[i][j] < minDist) // 가장 가까운 물고기
				{
					sharkX = i; sharkY = j;
					minDist = visited[i][j];
				}
			}
		}
	}

	if (minDist == INF) return false;
	else return true;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;

			if (input == 9)
			{
				sharkX = i;
				sharkY = j;
				map[i][j] = 0;
			}
		}
	}
	
	while (true)
	{
		bfs(sharkX, sharkY);

		if (find())
		{
			result += minDist;
			map[sharkX][sharkY] = 0;
			feed++;

			if (feed >= shark)
			{
				feed = 0;
				shark++;
			}
		}
		else break;
	}

	cout << result;
}