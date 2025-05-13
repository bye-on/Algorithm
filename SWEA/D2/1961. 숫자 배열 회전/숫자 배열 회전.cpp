#include<iostream>
#include <vector>
using namespace std;

int n;
// 90 회전
void rotation(vector<vector<int>> &map, vector<vector<int>> &tmp)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            map[j][n - i - 1] = tmp[i][j];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tmp[i][j] = map[i][j];
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << '\n';
        cin >> n;
        
        vector<vector<int>> map(n, vector<int>(n));
		vector<vector<int>> tmp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int input;
                cin >> input;
                map[i][j] = input;
                tmp[i][j] = input;
            }
        }
        
        vector<vector<int>> result(n);
        rotation(map, tmp);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
            	result[i].push_back(map[i][j]);
            }  
        }
        
        rotation(map, tmp);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
            	result[i].push_back(map[i][j]);
            }  
        }
        
        rotation(map, tmp);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
            	result[i].push_back(map[i][j]);
            }  
        }
        
       for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < result[i].size(); j++)
            {
            	cout << result[i][j];
                if((j+1)%n == 0)
                    cout << " ";
            }
           
           cout << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}