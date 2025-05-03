#include<iostream>
#include <vector>
using namespace std;

int calc(vector<vector<int>> &v, int x, int y, int m)
{
    int ret = 0;
    
    for(int i = x; i < (x+m); i++)
    {
        for(int j = y; j < (y + m); j++)
        {
            ret += v[i][j];
        }
    }
    
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> v(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int input;
                cin >> input;
                v[i].push_back(input);
            }
        }
        
        int maxnum = 0;
        for(int i = 0; i <= (n- m); i++)
        {
            for(int j = 0; j <= (n - m); j++)
            {
                maxnum = max(maxnum, calc(v, i, j, m));
            }
        }
        
        cout << "#" << test_case << " ";
        cout << maxnum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}