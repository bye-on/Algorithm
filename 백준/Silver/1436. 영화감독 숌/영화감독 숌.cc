#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 0;
	int temp = 0;
	while (true)
	{
		temp++;
		string str = to_string(temp);

		if (str.find("666") != string::npos)
			result++;
		if (result == n)
			break;
	}

	cout << temp;
}