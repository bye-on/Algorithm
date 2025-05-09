#include<iostream>
#include <vector>
using namespace std;
int map[9][9];

bool pruning() 
{
    for(int i = 0; i < 9; i++)
    {
        vector<bool> ok(10);
        for(int j = 0; j <9; j++)
        {
            if(!ok[map[i][j]])
                   ok[map[i][j]] = true;
            else
                   return false;
        }
    }
                   
    for(int i = 0; i < 9; i++)
    {
        vector<bool> ok(10);
        for(int j = 0; j <9; j++)
        {
            if(!ok[map[j][i]])
                   ok[map[j][i]] = true;
            else
                   return false;
        }
    }
                   
   for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 9; j += 3)
        {
            vector<bool> ok(10);
            for(int x = i; x < (i + 3); x++)
            {
                for(int y = j; y < (j + 3); y++)
                {
                    if(!ok[map[x][y]])
                   		ok[map[x][y]] = true;
                    else
                           return false;
                }
            }
        }
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
		for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cin >> map[i][j];
            }
        }
        
        cout << "#" << test_case << " ";
        if(pruning())
            cout << "1\n";
        else 
            cout << "0\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}