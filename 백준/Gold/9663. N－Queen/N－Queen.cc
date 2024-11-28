#include <iostream>
#include <vector>
using namespace std;

int n;

bool promising(vector<vector<bool>> &map, int row, int col)
{
	for (int i = row - 1, j = 1; i >= 0; i--, j++) // 이전 행(i)들 검사, j는 몇 번째 검사인지
	{
		if (map[i][col]) return false; // 수직
		if (col - j >= 0 && map[i][col - j]) return false; // 왼쪽 대각선
		if (col + j < map.size() && map[i][col + j]) return false; // 오른쪽 대각선
	}

	return true;
}

void queen(vector<vector<bool>> &map, int row, int &answer)
{
	if (row == n)
	{
		answer++;
		return;
	}

	for (int col = 0; col < n; col++) // 열
	{
		if (promising(map, row, col))
		{
			map[row][col] = true;
			queen(map, row + 1, answer);
			map[row][col] = false;
		}
	}
}

int main()
{
	cin >> n;
	int answer = 0;

	vector<vector<bool>> map(n, vector<bool>(n));
	queen(map, 0, answer);

	cout << answer;
}