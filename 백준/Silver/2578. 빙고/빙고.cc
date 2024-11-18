#include <iostream>
using namespace std;

int bingo[5][5];
int visited[5][5];

void check(int num)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i][j] == num)
			{
				visited[i][j] = true;
			}
		}
	}
}

bool checkBingo()
{
	int result = 0;
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		count = 0;
		
		for (int j = 0; j < 5; j++)
		{
			if (visited[i][j])
				count++;
		}
		
		if (count >= 5)
			result++;
	}

	for (int i = 0; i < 5; i++)
	{
		count = 0;

		for (int j = 0; j < 5; j++)
		{
			if (visited[j][i])
				count++;
		}

		if (count >= 5)
			result++;
	}

	count = 0;

	for (int i = 0; i < 5; i++)
	{
		if (visited[i][i])
			count++;
	}

	if (count >= 5)
		result++;

	count = 0;

	for (int i = 0; i < 5; i++)
	{
		if (visited[i][4 - i])
			count++;
	}

	if (count >= 5)
		result++;

	if (result >= 3)
		return true;
	else
		return false;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int input;
			cin >> input;
			bingo[i][j] = input;
		}
	}

	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int input;
			cin >> input;

			check(input);
			result++;

			if (checkBingo())
			{
				cout << result;
				return 0;
			}
		}
	}
}