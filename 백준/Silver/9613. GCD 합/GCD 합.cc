#include <iostream>
#include <vector>
using namespace std;

long long result = 0;
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void combination(vector<int>& comb, vector<int>& arr, int r, int index, int depth)
{
	if (r == 0)
	{
		if (comb[0] > comb[1])
			result += gcd(comb[0], comb[1]);
		else
			result += gcd(comb[1], comb[0]);

		return;
	}

	if (depth == arr.size())
		return;

	comb[index] = arr[depth];
	combination(comb, arr, r - 1, index + 1, depth + 1);
	combination(comb, arr, r, index, depth + 1);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
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

		result = 0;
		vector<int> comb(3);
		combination(comb, v, 2, 0, 0);

		cout << result << '\n';
	}
}