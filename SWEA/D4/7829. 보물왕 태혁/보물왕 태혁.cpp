#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        
        vector<int> v;
		for(int i = 0; i < n; i++)
        {
            int input;
            cin>>input;
            v.push_back(input);
        }
        
        sort(v.begin(), v.end());
        
        int result = v[n/2];

        if(n % 2 == 0)
            result *= v[n/2 - 1];
        else
            result *= v[n/2];
        
        cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}