#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
		{
			str[i] += 13;
			if (str[i] > 'z' || str[i] < 'a')
				str[i] -= 26;
		}
		else if (isupper(str[i]))
		{
			str[i] += 13;
			if (str[i] > 'Z' || str[i] < 'A')
				str[i] -= 26;
		}
		cout << str[i];
	}
}