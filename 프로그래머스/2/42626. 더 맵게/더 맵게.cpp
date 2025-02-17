#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<long long> pq;
    for(int i = 0; i < scoville.size(); i++)
    {
        pq.push(-scoville[i]);
    }
    
    bool isSpicy = false;
    while(pq.size() > 1)
    {
        long long a = -pq.top();
        pq.pop();
        long long b = -pq.top();
        pq.pop();
        
        if(a >= K)
        {
            isSpicy = true;
            break;
        }
        
        long long c = a + b * 2;

        pq.push(-c);
        answer++;
    }
    
    if(pq.size() == 1)
    {
        if(-pq.top() >= K)
        {
            isSpicy = true;
        }
    }
    
    if(isSpicy)
        return answer;
    else
        return -1;
}