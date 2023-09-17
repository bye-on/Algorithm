#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;
	typedef pair<int, string> word;
	vector<word> v;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(make_pair(str.length(), str));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << '\n';
	}
}