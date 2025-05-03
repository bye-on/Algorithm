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
        int n;
        cin >> n;
        
        vector<vector<int>> v(n, vector<int>(n));
        cout << "#" << test_case << "\n";
        for(int i = 0; i < n; i++)
        {
            v[i][0] = 1;
            for(int j = 1; j < i+1; j++)
            {
                v[i][j] = v[i-1][j] + v[i-1][j-1];
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i + 1; j++)
            {
               	cout << v[i][j] << " ";
            }
            cout << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}