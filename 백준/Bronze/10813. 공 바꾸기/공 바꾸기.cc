#include <iostream>
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

		int temp = basket[i];
		basket[i] = basket[j];
		basket[j] = temp;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << basket[i] << " ";
	}
}