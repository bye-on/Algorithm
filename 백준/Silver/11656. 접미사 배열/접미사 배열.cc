#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<string> v;
	for (int i = 0; i < str.length(); i++)
	{
		string temp;
		for (int j = i; j < str.length(); j++)
		{
			temp += str[j];
		}
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}