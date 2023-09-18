#include <iostream>
using namespace std;
int N, M;
int map[1002][1002];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int nx = i - 1;
			int ny = j - 1;

			map[i][j] += max(map[nx][ny], max(map[nx][j], map[i][ny]));
		}
	}
	cout << map[N][M];
}