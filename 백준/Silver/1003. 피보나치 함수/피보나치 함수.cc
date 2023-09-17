#include <iostream>
using namespace std;
int zeroCnt[41];
int oneCnt[41];

int main() {
	int T;
	cin >> T;
	zeroCnt[0] = 1; zeroCnt[1] = 0;
	oneCnt[0] = 0; oneCnt[1] = 1;

	for (int i = 0; i < T; i++) {
		int input;
		cin >> input;
		if (input == 0) {
			cout << zeroCnt[0] << " " << oneCnt[0] << endl;
			continue;
		}
		if (input == 1) {
			cout << zeroCnt[1] << " " << oneCnt[1] << endl;
			continue;
		}
		for (int j = 2; j <= input; j++) {
			zeroCnt[j] = zeroCnt[j - 1] + zeroCnt[j - 2];
			oneCnt[j] = oneCnt[j - 1] + oneCnt[j - 2];
		}
		cout << zeroCnt[input] << " " << oneCnt[input] << endl;
	}
}