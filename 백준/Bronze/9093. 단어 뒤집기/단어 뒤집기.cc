#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);

		vector<string> words;
		int index = 0;
		while ((index = str.find(" ")) != string::npos)
		{
			words.push_back(str.substr(0, index));
			str.erase(0, index + 1);
		}
		words.push_back(str);

		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < words[i].size(); j++)
			{
				cout << words[i][words[i].size() - 1 - j];
			}
			cout << " ";
		}
		cout << '\n';
	}
}