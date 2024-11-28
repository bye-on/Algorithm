#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main()
{
	int n, r;
	cin >> n >> r;

	vector<int> v;
	vector<int> visited(n);

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < r; i++)
	{
		visited[i] = true;
	}

	do
	{
		for (int i = 0; i < v.size(); i++)
			if(visited[i])
				cout << v[i] << " ";
		cout << '\n';
	} while (prev_permutation(visited.begin(), visited.end()));
}
