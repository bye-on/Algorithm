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

	vector<int> lis;
	vector<int> path;

	for (int i = 0; i < n; i++)
	{
		int num = v[i];
		int index = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
		if (index == lis.size())
		{
			lis.push_back(num);
			path.push_back(lis.size() - 1);
		}
		else
		{
			lis[index] = num;
			path.push_back(index);
		}
	}

	vector<int> result;
	int length = lis.size() - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (path[i] == length)
		{
			result.push_back(v[i]);
			length--;
		}
	}
    
    cout << lis.size() << '\n';
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}