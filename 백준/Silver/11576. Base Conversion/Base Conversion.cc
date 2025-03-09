#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, m;
	cin >> A >> B >> m;
	
	int num = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		int input;
		cin >> input;

		int temp = pow(A, i) * input;
		num += temp;
	}

	vector<int> v;
	while (num != 0)
	{
		v.push_back(num % B);
		num /= B;
	}

	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}