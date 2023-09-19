#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int RGB[1001][3];

int main() {
	int N;
	cin >> N;
	vector<int> v;

	int index;
	for (int i = 0; i < 3; i++) {
		int input;
		cin >> input;
		RGB[1][i] = input;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			int input;
			cin >> input;
			v.push_back(input);
		}
		for (int j = 0; j < 3; j++) {
			if (RGB[i - 1][(j + 1) % 3] < RGB[i - 1][(j + 2) % 3]) {
				RGB[i][j] = v[j] + RGB[i - 1][(j + 1) % 3];
			}
			else {
				RGB[i][j] = v[j] + RGB[i - 1][(j + 2) % 3];
			}
		}
		v.clear();
	}

	cout << min(RGB[N][2], min(RGB[N][0], RGB[N][1]));
}