#include<iostream>
using namespace std;

bool pattern(int s, int e, string str)
{
    for(int i = 0; i < (e - s); i++)
    {
        if(str[s + i] != str[e + i])
            return false;
    }
    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str;
        cin >> str;
        char index = 0;
        
        for(int i = 1; i < str.size(); i++)
        {
            if(str[index] == str[i])
            {
                if(pattern(index, i, str))
                {
                    cout << "#" << test_case << " " << i - index <<'\n';
                    break;
                }
            }
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}