#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int result = 1;
	int e = 1; int s = 1; int m = 1;
	while (true)
	{
		if (E == e && S == s && M == m)
			break;

		result++;
		e++; s++; m++;

		if (e > 15)
			e /= 15;
		if (s > 28)
			s /= 28;
		if (m > 19)
			m /= 19;
	}

	cout << result;
}