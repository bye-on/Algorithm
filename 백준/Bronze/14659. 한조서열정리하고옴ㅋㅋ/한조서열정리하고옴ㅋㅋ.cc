#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	int maxResult = 0;
	int result = 0;
	int start = v[0];
	for (int i = 1; i < N; i++)
	{
		if (start > v[i])
		{
			maxResult++;
			result = max(result, maxResult);
		}
		else
		{
			start = v[i];
			result = max(result, maxResult);
			maxResult = 0;
		}
	}

	cout << result;
}