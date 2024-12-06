#include<vector>
#include<stack>
#include<iostream>
using namespace std;
int v[100][2];
bool visited[100];

bool dfs()
{
    stack<int> s;
    s.push(0);
    
    while(!s.empty())
    {
        int current = s.top();
        if(current == 99)
            return true;
        visited[current] = true;
        s.pop();
        
        int next = v[current][0];
        if(next != 0 && !visited[next])
            s.push(next);
        
        next = v[current][1];
        if(next != 0 && !visited[next])
            s.push(next);
    }
    return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int num;
		cin >> T >> num;
        
        for(int i = 0; i < 100; i++)
        {
            visited[i] = false;
            for(int j = 0; j < 2; j++)
            {
                v[i][j] = 0;
            }
        }
        
        
		for(int i = 0; i < num; i++)
        {
            int a, b;
            cin >> a >> b;
         	if(v[a][0] == 0)
                v[a][0] = b;
            else 
                v[a][1] = b;
        }

        if(dfs()) 
            cout << "#" << T << " " << "1" << '\n';
        else 
            cout << "#" << T << " " << "0" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}