#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		deque<int> d;

		string p; int n; string str;
		cin >> p >> n >> str;

		int digits = 0;
		int num = 0;
		for (int j = str.length() - 2; j >= 0 ; j--)
		{
			int temp = str[j] - '0';

			if (temp >= 0 && temp < 10)
			{
				num += (temp * pow(10, digits++));
			}
			else
			{
				if (num > 0)
				{
					d.push_back(num);
					num = 0;
					digits = 0;
				}
			}
		}
		
		bool back = true;
		bool err = false;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
				back = !back;
			else
			{
				if (d.size() <= 0)
				{
					err = true;
					cout << "error\n";
					break;
				}
				else
				{
					if (back)
						d.pop_back();
					else
						d.pop_front();
				}
			}
		}
		
		vector<string> v;
		if(!err)
		{
			v.push_back("[");
			if (back)
			{
				while (d.size() > 1)
				{
					v.push_back(to_string(d.back()));
					v.push_back(",");
					d.pop_back();
				}
				if (d.size() == 1)
					v.push_back(to_string(d.back()));
			}
			else
			{
				while (d.size() > 1)
				{
					v.push_back(to_string(d.front()));
					v.push_back(",");
					d.pop_front();
				}
				if (d.size() == 1)
					v.push_back(to_string(d.front()));
			}
			v.push_back("]");

			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			}
			cout << '\n';
		}
	}
}