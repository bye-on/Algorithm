#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	
	int min = 1e9; int max = -1e9;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		
		if (min > input)
			min = input;
		if (max < input)
			max = input;
	}
	
	cout << min << " " << max;
}