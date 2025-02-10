#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1000001];
int n[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr[i] = input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << " ";
	}
}