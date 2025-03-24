#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;

	vector<int> router;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		router.push_back(input);
	}

	sort(router.begin(), router.end());

	int start = 0; int end = router[router.size() - 1];
	int maxdis = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		int cnt = c - 1; int index = 0;
		for (int i = 1; i < router.size(); i++)
		{
			int distance = router[i] - router[index];
			if (distance >= mid)
			{
				cnt--;
				index = i;
			}
		}

		if (cnt <= 0)
		{
			maxdis = max(maxdis, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << maxdis;
}