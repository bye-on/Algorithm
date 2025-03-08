#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

bool visited[10000];

void calc(int a, int b)
{
	queue<pair<int, string>> q;
	q.push({ a, "" });

	while (!q.empty())
	{
		int num = q.front().first;
		string op = q.front().second;
		q.pop();

		if (num == b)
		{
			cout << op << '\n';
			return;
		}

		string temp = to_string(num);
		string ret = "";
		if (num < 1000)
		{
			for (int i = 0; i < 4 - temp.length(); i++)
			{
				ret += "0";
			}
			ret += temp;
			temp = ret;
		}

		int d = (num * 2) % 10000;
		if (!visited[d])
		{
			q.push({ d, op + "D" });
			visited[d] = true;
		}

		int s = (num - 1) < 0 ? 9999 : num - 1;
		if (!visited[s])
		{
			q.push({ s, op + "S" });
			visited[s] = true;
		}
		
		int l = (num % 1000) * 10 + (num / 1000);
		if (!visited[l])
		{
			q.push({ l , op + "L" });
			visited[l] = true;
		}

		int r = (num % 10) * 1000 + (num / 10);
		if (!visited[r])
		{
			q.push({ r, op + "R" });
			visited[r] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int i = 0; i < 10000; i++)
		{
			visited[i] = false;
		}

		calc(a, b);
	}
}