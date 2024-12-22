#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
bool visited[200001];
int N, K;

void bfs() {
	q.push(make_pair(N, 0));
	visited[N];

	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();
		if (pos < 0 || pos > 100000) continue;
		if (pos == K) {
			cout << time;
			break;
		}
		if (!visited[pos * 2]) {
			visited[pos * 2] = true;
			q.push(make_pair(pos * 2, time + 1));
		}
		if (!visited[pos + 1]) {
			visited[pos + 1] = true;
			q.push(make_pair(pos + 1, time + 1));
		}
		if (!visited[pos - 1]) {
			visited[pos - 1] = true;
			q.push(make_pair(pos - 1, time + 1));
		}
	}
}

int main() {
	cin >> N >> K;
	bfs();
}