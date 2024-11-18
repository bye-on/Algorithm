#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void switchNum(int index)
{
	if (v[index] == 1)
		v[index] = 0;
	else
		v[index] = 1;
}

void man(int num)
{
	int index = 1;

	while (true)
	{
		int current = num * index;

		if (current > v.size())
			break;

		switchNum(current - 1);
		index++;
	}
}

void woman(int num)
{
	int index = 1;

	while (true)
	{
		int left = num - index - 1;
		int right = num + index - 1;

		if (left < 0 || right > v.size() - 1)
		{
			switchNum(num - 1);
			break;
		}

		if (v[left] != v[right])
		{
			switchNum(num - 1);
			break;
		}
		else
		{
			switchNum(left); 
			switchNum(right);
		}

		index++;
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int wc, num;
		cin >> wc >> num;

		switch (wc)
		{
		case 1:
			man(num);
			break;
		case 2:
			woman(num);
			break;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";

		if ((i + 1) % 20 == 0)
			cout << '\n';
	}
}