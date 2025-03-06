#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int index = 0; int sum = 0; string result = "";
	for (int i = str.length() - 1; i >= 0; i--)
	{
		int num = str[i] - '0';
		sum += num * pow(2, index++);

		if (index == 3)
		{
			index = 0;
			result += to_string(sum);
			sum = 0;
		}
	}

	if(index != 0)
		result += to_string(sum);
	reverse(result.begin(), result.end());

	cout << result;
}