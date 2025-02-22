#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<pair<int, int>, string>> v;
	for (int i = 0; i < n; i++)
	{
		int age; string name;
		cin >> age >> name;
		v.push_back({ { age, i }, name });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first.first << " " << v[i].second << '\n';
	}
}