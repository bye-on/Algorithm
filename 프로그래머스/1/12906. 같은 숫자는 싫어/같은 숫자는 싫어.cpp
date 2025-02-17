#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    deque<int> q;
    for(int i = 0; i < arr.size(); i++)
    {
        if(q.empty())
            q.push_back(arr[i]);
        else
        {
            if(q.back() != arr[i])
                q.push_back(arr[i]);
        }
    }
    
    while(!q.empty())
    {
        answer.push_back(q.front());
        q.pop_front();
    }

    return answer;
}