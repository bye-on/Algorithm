#include <iostream>
#include <sstream>
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

		stringstream ss(str);
		string word;
		while (getline(ss, word, ' '))
		{
			for (int j = 0; j < word.size(); j++)
			{
				cout << word[word.size() - 1 - j];
			}
			cout << " ";
		}
		cout << '\n';
	}
}