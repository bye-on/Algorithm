#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long a, b;
	cin >> a >> b;
	
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < a; i++)
	{
		int input;
		cin >> input;
		A.push_back(input);
	}

	for (int i = 0; i < b; i++)
	{
		int input;
		cin >> input;
		B.push_back(input);
	}

	vector<int> v;
	int indexA = 0; int indexB = 0;
	while (true)
	{
		if (indexA == A.size())
		{
			for (int i = indexB; i < B.size(); i++)
			{
				v.push_back(B[i]);
			}
			break;
		}
		if (indexB == B.size())
		{
			for (int i = indexA; i < A.size(); i++)
			{
				v.push_back(A[i]);
			}
			break;
		}

		if (A[indexA] <= B[indexB])
		{
			v.push_back(A[indexA++]);
		}
		else
		{
			v.push_back(B[indexB++]);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}