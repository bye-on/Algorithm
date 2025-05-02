#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int a, b, n;
        cin >> a >> b >> n;
        
        int result = 0;
        int cnt = 0;
        while(result <= n) 
        {
			result = a + b;
            
            if(a < b)
                a = result;
            else
                b = result;
            
            cnt++;
        }
        cout << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}