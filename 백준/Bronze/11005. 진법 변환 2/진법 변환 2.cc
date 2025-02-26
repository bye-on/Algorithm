#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long str; long long n;
	cin >> str >> n;
	
	string result = "";
	while (str != 0)
	{
		int remain = str % n;
		str /= n;

		if (remain >= 10)
		{
			int temp = remain - 10;
			for (int i = 0; i < 26; i++)
			{
				if (('A' + i - 'A') == temp)
				{
					char c = 'A' + i;
					result += c;
					break;
				}
			}
		}
		else
		{
			result += (remain + '0');
		}
	}

	reverse(result.begin(), result.end());
	cout << result;
}