#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    
	//freopen("input.txt", "r", stdin);


	for(test_case = 1; test_case <= 10; ++test_case)
	{
        cin>>T;		
        
        string str;
        cin>> str;
        
        int result = 0;
        for(int i = 0; i < T; i += 2)
        {
            result += str[i] - '0';
        }
        
        cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}