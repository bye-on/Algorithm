#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> temp;
    for(int i = 0; i < progresses.size(); i++)
    {
        int remain = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) 
            remain++;
        temp.push_back(remain);
    }
    
    int cnt = 0; int first = temp[0];
    for(int i = 1; i < temp.size(); i++)
    {
        if(first < temp[i])
        {
            answer.push_back(++cnt);
            cnt = 0;
            first = temp[i];
        }
        else
            cnt++;
    }
    answer.push_back(++cnt);
    
    return answer;
}