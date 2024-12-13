#include<queue>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
        cout << "#" << T << " ";
        
        queue<int> q;
        for(int i = 0; i < 8; i++)
        {
            int input;
            cin >> input;
            q.push(input);
        }
        
        int cycle = 1;
        while(true)
        {
            if(cycle > 5)
                cycle = 1;
            
            int top = q.front();
            q.pop();
            top -= cycle;
            if(top > 0)
            {
                cycle++;
                q.push(top);
            }
            else
            {
                q.push(0);
                break;
            }
        }
		
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}