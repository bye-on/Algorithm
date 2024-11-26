#include <iostream>
#include <vector>
using namespace std;

bool josephus[5001];
int main()
{
	int n, k;
	cin >> n >> k;

	int result = 0;
	int count = 0;
	cout << "<";

	while (true)
	{
		if (result >= n)
			break;

		for (int i = 0; i < k; )
		{
			count++;
			if (count > n)
				count %= n;

			if (!josephus[count])
				i++;
		}

		
		josephus[count] = true;
		result++;

		if (result < n)
			cout << count << ", ";
	}

	cout << count << ">";
}