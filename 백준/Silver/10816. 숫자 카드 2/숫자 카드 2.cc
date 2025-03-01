#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	map<long long, long long> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		if (m.find(input) != m.end())
			m[input]++;
		else
			m.insert({ input, 1 });
	}

	int l;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int input;
		cin >> input;
		if (m.find(input) != m.end())
			cout << m[input] << " ";
		else
			cout << "0 ";
	}
}