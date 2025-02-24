#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime[45001];
void prime()
{
	isPrime[1] = true; // 1은 소수 아님
	for (int i = 2; i * i < 45001; i++)
	{
		if (isPrime[i]) // 소수인 것만 판별
			continue;

		for (int j = i + i; j * i < 45001; j += i)
		{
			isPrime[j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	prime();
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		
		int result = a * b;
		int temp = 1;

		int index = 2;
		while (a >= index && b >= index)
		{
			if (!isPrime[index])
			{
				do
				{
					if (a % index == 0 && b % index == 0)
					{
						temp *= index;
						a /= index;
						b /= index;
					}
				} while (a % index == 0 && b % index == 0);

				index++;
			}
			else
				index++;
		}

		cout << result / temp << '\n';
	}
}