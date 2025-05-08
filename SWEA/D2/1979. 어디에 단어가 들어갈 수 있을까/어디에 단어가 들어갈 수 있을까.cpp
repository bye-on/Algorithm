#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int n, m;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
int map[16][16];
int answer = 0;

void bfs(int i, int j, vector<vector<bool>>& visited, int d)
{
    queue<pair<int, int>> q;
    q.push({ i, j });
    int result = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        visited[i][j] = true;
        result++;
        q.pop();

        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (!visited[nx][ny] && map[nx][ny] == 1)
        {
            q.push({ nx,ny });
            visited[nx][ny] = true;
        }
    }

    if (result == m)
        answer++;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        answer = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                    bfs(i, j, visited, 0);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                    bfs(i, j, visited, 1);
            }
        }

        cout << "#" << test_case << " ";
        cout << answer << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}