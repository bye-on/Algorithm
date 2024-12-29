#include <iostream>
#include <queue>
using namespace std;

int map[126][126];
int d[126][126];
int n;
int INF = 1e9;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = 0;
			d[i][j] = INF;
		}
	}
}

void dijkstra(int x, int y)
{
	priority_queue<pair<int, pair<int, int>>> pq;
	d[x][y] = map[x][y];
	pq.push({ -map[x][y], {x,y} });
	
	while (!pq.empty())
	{
		int current = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next = current + map[nx][ny];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (d[nx][ny] > next)
			{
				pq.push({ -next,{nx, ny} });
				d[nx][ny] = next;
			}
		}
	}
}

int main()
{
	int index = 1;

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		Init();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int input;
				cin >> input;
				map[i][j] = input;
			}
		}

		dijkstra(0, 0);
		cout << "Problem " << index++ << ": ";
		cout << d[n-1][n-1]<<'\n';
	}
}