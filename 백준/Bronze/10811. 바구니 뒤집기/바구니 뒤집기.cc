#include <iostream>
#include <vector>
using namespace std;

int basket[101];

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		basket[i] = i;
	}

	for (int m = 0; m < M; m++)
	{
		int i, j;
		cin >> i >> j;

		vector<int> v;
		for (int a = j; a >= i; a--)
		{
			v.push_back(basket[a]);
		}

		for (int a = 0; a < v.size(); a++)
		{
			basket[i + a] = v[a];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << basket[i] << " ";
	}
}