#include<iostream>

using namespace std;

int multiply(int n, int m)
{
    if(m <= 0) return 1;
   	return multiply(n, m - 1) * n;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
        int n, m;
        cin>> n >>m;
        cout << "#" << T << " " << multiply(n, m) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}