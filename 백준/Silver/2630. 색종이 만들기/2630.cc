#include <iostream>
using namespace std;
int N;
int BlueCnt = 0;
int WhiteCnt = 0;
int map[128][128];

void Paper(int x, int y, int n) {
	bool isDiff = false;
	if (n == 1) {
		if (map[x][y] == 1) BlueCnt++;
		else WhiteCnt++;
		return;
	}
	int w = x + (n / 2);
	int h = y + (n / 2);

	for (int i = x; i < n + x; i++) {
		for (int j = y; j < n + y; j++) {
			if (map[i][j] != map[x][y]) {
				isDiff = true;
				break;
			}
		}
	}
	if (isDiff) {
		Paper(x, y, n / 2);
		Paper(x, h, n / 2);
		Paper(w, y, n / 2);
		Paper(w, h, n / 2);
	}
	else {
		if (map[x][y] == 1) BlueCnt++;
		else WhiteCnt++;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}
	Paper(0, 0, N);
	cout << WhiteCnt << '\n' << BlueCnt;
}