#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; string str;
		cin >> n >> str;
		vector<string> v;

		string temp = str;
		for (int i = 0; i < str.length(); i++)
		{
			v.push_back(temp.substr(i));
		}

		sort(v.begin(), v.end());

		cout << "#" << test_case << " ";
		cout << v[n - 1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}