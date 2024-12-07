#include<iostream>
bool visited[10];
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(int i = 0; i < 10; i++)
            visited[i] = false;
        
        int count = 0;
        string str;
        cin >> str;
        
        for(int i = 0; i < str.length(); i++)
        {
            if(!visited[str[i] - '0'])
            {
                visited[str[i] - '0'] = true;
                count++;
            }
        }
		cout << "#" << test_case << " " << count << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}