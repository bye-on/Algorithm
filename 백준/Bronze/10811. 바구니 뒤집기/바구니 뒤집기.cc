#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> basket;
	for (int i = 1; i <= N; i++)
	{
		basket.push_back(i);
	}

	for (int m = 0; m < M; m++)
	{
		int i, j;
		cin >> i >> j;

		reverse(basket.begin() + i - 1, basket.begin() + j);
	}

	for (int i = 0; i < basket.size(); i++)
	{
		cout << basket[i] << " ";
	}
}