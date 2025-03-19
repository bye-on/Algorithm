#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	vector<int> nge(n);
	stack<int> s;
	for (int i = 0; i < v.size(); i++)
	{
		while (!s.empty() && v[s.top()] < v[i])
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