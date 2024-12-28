#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
        string p, str;
        cin >> p >> str;
		
        int result = 0;
        int index = 0;
        while((index = str.find(p)) != string::npos)
        {
            result++;
            str = str.substr(index+1);
        }
        cout << "#" << T << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}