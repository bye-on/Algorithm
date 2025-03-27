#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool visited[26];

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		
		
		int ss = 0;
		vector<string> v;
		while ((ss = str.find(" ")) != string::npos)
		{
			string tmp = str.substr(0, ss);
			v.push_back(tmp);
			str.erase(0, ss + 1);
		}
		v.push_back(str);

		int si = -1; int ei = -1;
		bool ok = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i][0] >= 'A' && v[i][0] <= 'Z')
			{
				int num = v[i][0] - 'A';
				if (!visited[num])
				{
					visited[num] = true;
					si = i; ei = 0;
					ok = true;
					break;
				}
			}

			if (v[i][0] >= 'a' && v[i][0] <= 'z')
			{
				int num = v[i][0] - 'a';
				if (!visited[num])
				{
					visited[num] = true;
					si = i; ei = 0;
					ok = true;
					break;
				}
			}
		}

		
		for (int i = 0; i < v.size(); i++)
		{
			if (!ok)
			{
				for (int j = 0; j < v[i].size(); j++)
				{
					if (v[i][j] >= 'A' && v[i][j] <= 'Z')
					{
						int num = v[i][j] - 'A';
						if (!visited[num])
						{
							visited[num] = true;
							si = i; ei = j;
							ok = true;
							break;
						}
					}

					if (v[i][j] >= 'a' && v[i][j] <= 'z')
					{
						int num = v[i][j] - 'a';
						if (!visited[num])
						{
							visited[num] = true;
							si = i; ei = j;
							ok = true;
							break;
						}
					}
				}

			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (si == i && ei == j)
					cout << "[" << v[i][j] << "]";
				else
					cout << v[i][j];
			}
			cout << " ";
		}

		cout << '\n';
	}
}