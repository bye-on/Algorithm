#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n;
    cin >> n;
    
    int result = 0;
    while(true)
    {
        result += (n%10);
        n /= 10;
        
        if(n == 0)
            break;
    }
    
    cout << result;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}