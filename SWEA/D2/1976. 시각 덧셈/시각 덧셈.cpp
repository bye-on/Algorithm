#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int hour = ((a1 + a2) + ((b1 + b2) / 60)) % 12;
        if(hour == 0)
            hour = 12;
        int minute = (b1 + b2) % 60;
        
        cout << "#" << test_case << " ";
        cout << hour << " " << minute << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}