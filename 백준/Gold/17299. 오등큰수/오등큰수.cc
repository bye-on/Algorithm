#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> cnt(1000001);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);

		cnt[input]++;
	}

	vector<int> nge(n);
	stack<int> s;
	for (int i = 0; i < v.size(); i++)
	{
		while (!s.empty() && cnt[v[s.top()]] < cnt[v[i]])
		{
			nge[s.top()] = v[i];
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		nge[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < nge.size(); i++)
	{
		cout << nge[i] << " ";
	}
}