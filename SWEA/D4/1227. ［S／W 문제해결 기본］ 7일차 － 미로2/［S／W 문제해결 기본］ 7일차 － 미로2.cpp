#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[100][100];
bool visited[100][100];

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;
            if (!visited[nx][ny])
            {
                if (map[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
                if (map[nx][ny] == 3)
                    return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;


    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> T;
        cout << "#" << T << " ";

        int x; int y;
        for (int i = 0; i < 100; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < str.length(); j++)
            {
                map[i][j] = str[j] - '0';
                visited[i][j] = false;

                if (str[j] - '0' == 2)
                {
                    x = i;
                    y = j;
                }
            }
        }

        if (bfs(x, y)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}