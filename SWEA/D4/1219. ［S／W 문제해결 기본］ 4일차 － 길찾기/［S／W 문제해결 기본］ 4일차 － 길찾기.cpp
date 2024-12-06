#include<vector>
#include<iostream>
using namespace std;
vector<int> v[100];
bool visited[100];

void dfs(int x)
{
    visited[x] = true;
 	
    for(int i = 0; i < v[x].size(); i++)
    {
        int next = v[x][i];
        
        if(!visited[next])
            dfs(next);
    }
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
            v[i].clear();
        }
        
		for(int i = 0; i < num; i++)
        {
            int a, b;
            cin >> a >> b;
         	v[a].push_back(b);
        }
        
        dfs(0);

        if(visited[99]) 
            cout << "#" << T << " " << "1" << '\n';
        else 
            cout << "#" << T << " " << "0" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}