#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> v;
        for(int i = 0; i < 10; i++)
        {
            int input;
            cin >> input;
            v.push_back(input);
        }
        
        sort(v.begin(), v.end());
        
        float result = 0;
        for(int i = 1; i < v.size() - 1; i++)
        {
            result += v[i];
        }
        
        cout << "#" << test_case << " ";
        cout << round(result / 8) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}