#include <iostream>
#include <vector>
using namespace std;

bool visited[100001];
bool done[100001];
int cnt = 0;

void dfs(vector<int>& v, int start)
{
	visited[start] = true; // 방문 처리
	int next = v[start];

	if (!visited[next]) // 이미 들른 곳인가? 아니면 더 깊게 탐색
	{
		dfs(v, next);
	}
	else if (!done[next]) // 이미 방문 및 확인할 곳인가? 맞다면 사이클 有
	{
		for (int i = next; i != start; i = v[i])
		{
			cnt++;
		}
		cnt++; // 본인++;
	}
	// else -> 이미 방문 및 확인하여 사이클 처리를 한 애들

	done[start] = true; // 확인 처리
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;

		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++)
		{
			int input;
			cin >> input;
			v[i] = input;
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				dfs(v, i);
		}

		cout << n - cnt << '\n';
		cnt = 0;

		for (int i = 0; i <= n; i++)
		{
			visited[i] = false;
			done[i] = false;
		}
	}
}