#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool broken[10];

bool isPossible(int n)
{
	string str = to_string(n);

	for (int i = 0; i < str.length(); i++)
	{
		int num = str[i] - '0';

		if (broken[num])
			return false;
	}

	return true;
}
int main()
{
	int channel, n;
	cin >> channel >> n;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		broken[input] = true;
	}

	int updown = abs(channel - 100);
	int dial = 1e9;
	
	for (int i = 0; i < 1000001; i++)
	{
		if (isPossible(i))
		{
			int temp = abs(i - channel) + to_string(i).size();
			dial = min(temp, dial);
		}
	}
	
	cout << min(updown, dial);
}