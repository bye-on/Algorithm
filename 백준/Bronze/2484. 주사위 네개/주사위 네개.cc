#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	int n;
	cin >> n;

	int maxnum = 0;
	for (int i = 0; i < n; i++)
	{
		map<int, int> dice;
		for (int j = 0; j < 4; j++)
		{
			int input;
			cin >> input;
			if (dice.find(input) != dice.end())
				dice[input]++;
			else
				dice.insert({ input, 1 });
		}

		vector<pair<int, int>> v(dice.begin(), dice.end());
		sort(v.begin(), v.end(), cmp);

		int result = 0;
		
		if (v[0].second == 4)
		{
			result += (50000 + (v[0].first * 5000));
		}
		else if (v[0].second == 3)
		{
			result += (10000 + (v[0].first * 1000));
		}
		else if (v[0].second == 2)
		{
			if (v[1].second == 2)
			{
				result += (2000 + (v[0].first * 500) + (v[1].first * 500));
			}
			else
			{
				result += (1000 + (v[0].first * 100));
			}
		}
		else
		{
			result += (v[0].first * 100);
		}

		maxnum = max(maxnum, result);
	}

	cout << maxnum;
}