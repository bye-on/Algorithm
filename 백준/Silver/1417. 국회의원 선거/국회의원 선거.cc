#include <iostream>
#include <vector>
#include <algorithm>
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

	int dasom = v[0];
	int result = 0;

	if (n > 1)
	{
		while (true)
		{
			sort(v.begin() + 1, v.end());
			reverse(v.begin() + 1, v.end());

			if (dasom <= v[1])
			{
				dasom++;
				v[1]--;
				result++;
			}
			else
				break;
		}
	}
	
	cout << result;
}