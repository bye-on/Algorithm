#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n;
    cin >> n;
    
    long long start = 1; long long end = n;
    vector<int> v;
    while(start < end)
    {
        long long num = start * end;
        if(num == n)
        {
            v.push_back(start);
            v.push_back(end);
            start++; end--;
        }
        else if(num > n)
            end--;
        else 
            start++;
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}