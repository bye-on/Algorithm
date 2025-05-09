#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int num;
        cin >> num;
        
        vector<int> v;
        int m=50000;
        for(int i = 0; i < 8; i++)
        {
            v.push_back(num / m);
            num %= m;
            
            if(i % 2 == 0)
                m /= 5;
            else
                m /= 2;
        }
        cout << "#" << test_case << '\n';
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}