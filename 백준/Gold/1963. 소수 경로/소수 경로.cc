#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool isPrime[10000];
bool visited[10000];

void prime()
{
	for (int i = 2; i * i < 10000; i++)
	{
		if (isPrime[i]) continue; // 소수만 판별
		for (int j = i + i; j < 10000; j += i)
		{
			isPrime[j] = true;
		}
	}
}

void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({a, 0});

	while (!q.empty())
	{
		int top = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[top] = true;

		if (top == b)
		{
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				string temp = to_string(top);
				temp[i] = j + '0';
				int num = stoi(temp);

				if (num < 1000 || num >10000) continue;
				if (!visited[num] && !isPrime[num])
				{
					visited[num] = true;
					q.push({ num, cnt + 1 });
				}
			}
		}
	}

	cout << "Impossible\n";
	return;
}

int main()
{
	prime();

	int t;
	cin >> t;	
	for (int c = 0; c < t; c++)
	{
		int a, b;
		cin >> a >> b;

		for (int i = 0; i < 10000; i++)
		{
			visited[i] = false;
		}

		bfs(a, b);
	}
}