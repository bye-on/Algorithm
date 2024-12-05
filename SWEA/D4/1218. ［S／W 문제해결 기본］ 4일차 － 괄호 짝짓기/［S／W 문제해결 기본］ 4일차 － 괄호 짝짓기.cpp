#include <stack>
#include<iostream>
using namespace std;

// 1. 왼쪽 괄호 개수 == 오른쪽 괄호 개수
// 2. 괄호 짝 중 왼쪽 괄호가 먼저 나와야 함
// 3. 괄호 사이에는 포함 관계만 존재

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
        string str;
        cin >> str;
        
        stack<char> stackPair;
        int result = 1; // 유효성
        
        for(int i = 0; i < T; i++)
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<')
                stackPair.push(str[i]);
            else // 오른쪽 괄호일 때
            {
                if(!stackPair.empty())
                {
                    char c = stackPair.top();
                    stackPair.pop();
                    
                    if(c == '(')
                    {
                        if(str[i] != ')')
                        {
                            result = 0;
                            break;
                        }
                    } 
                    if(c == '{')
                    {
                        if(str[i] != '}')
                        {
                            result = 0;
                            break;
                        }
                    }
                    if(c == '[')
                    {
                        if(str[i] != ']')
                        {
                            result = 0;
                            break;
                        }
                    }  
                    if(c == '<')
                    {
                        if(str[i] != '>')
                        {
                            result = 0;
                            break;
                        }
                    }   
                }
                else // 오른쪽 괄호 뿐일 때
                {
                    result = 0;
                    break;
                }          
            }
        }
        
        if(!stackPair.empty()) // 괄호 남아있음
            result = 0;
        
        cout << "#" << test_case << " " << result << '\n';
	}
	return 0; //정상종료시 반드시 0을 리턴해야합니다.
}