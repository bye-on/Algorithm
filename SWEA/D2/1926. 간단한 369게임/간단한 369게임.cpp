#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int N;
    cin >> N;
    
    for(int i = 1; i <=N; i++)
    {
		int cnt = 0;
        int n = i;
        int tmp = 0;
        while(true)
        {            
            tmp = (n % 10);
			
            if(tmp != 0)
            {
                if(tmp % 3 == 0)
                cnt++;
            }
            
            n /= 10;
            if(n == 0)
                break; 
        }
        
        if(cnt > 0)
        {
            for(int j = 0; j < cnt; j++)
                cout << '-';
            cout << ' ';
        }
        else
            cout << i << ' ';
    }
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}