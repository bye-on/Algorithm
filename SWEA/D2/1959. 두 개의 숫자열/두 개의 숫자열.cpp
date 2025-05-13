#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{	
        int n, m;
        cin >> n >> m;
        
        vector<int> A;
        vector<int> B;
        for(int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            A.push_back(input);
        }
        for(int i = 0; i < m; i++)
        {
            int input;
            cin >> input;
            B.push_back(input);
        }
       	
        long long result = 0; int index = 0; int index2 = 0;
        if(n > m) 
        {
            index = n - m;
            index2 = m;
        }
        else
        {
            index = m - n;
            index2 = n;
        }
        
        for(int i = 0; i <= index; i++)
        {
            long long tmp = 0;
            for(int j = 0; j < index2; j++)
            {
                if(n < m)
                	tmp += (A[j] * B[i + j]);
                else
                    tmp += (A[i + j] * B[j]);
            }
            result = max(result, tmp);
        }
        
        cout << "#" << test_case << " ";
        cout << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}