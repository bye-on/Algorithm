#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string str;
	cin >> str;

	string result = "";
	for (int i = str.length() - 1; i >= 0; i--)
	{
		string temp = "";
		int num = str[i] - '0';
		for (int j = 2; j >= 0; j--)
		{
			int m = pow(2, j);

			temp += to_string(num / m);
			num = num % m;
		}
		reverse(temp.begin(), temp.end());
		result += temp;
	}

	reverse(result.begin(), result.end());

	bool isok = false;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != '0')
		{
			isok = true;
		}

		if(isok)
			cout << result[i];
	}

	if (!isok)
		cout << "0";
}