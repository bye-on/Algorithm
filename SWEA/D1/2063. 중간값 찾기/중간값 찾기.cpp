#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
    vector<int> v;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int input;
        cin >> input;
        v.push_back(input);
	}
    sort(v.begin(), v.end());
    cout << v[v.size()/2];
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}