#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, k;
    	cin >> n >> k;
        
        vector<pair<double, int>> v;
        for(int i = 0; i < n; i++)
        {
            double result = 0;
            int a, b, c;
        	cin >> a>> b >> c;
            
            result += (a * 0.35);
        	result += (b * 0.45);
            result += (c * 0.2);
            
            v.push_back({result, i});
        } 
        
        cout << "#" << test_case << " ";
       	sort(v.rbegin(), v.rend());

        int index = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].second == (k - 1))
            {
                index = i;
                break;
            }
        }
        
        index = (index) / (n / 10);
        switch(index)
        {
            case 0:
                cout << "A+\n";
                break;
            case 1:
                cout << "A0\n";
                break;
            case 2:
                cout << "A-\n";
                break;
            case 3:
                cout << "B+\n";
                    break;
            case 4:
                cout << "B0\n";
                break;
            case 5:
                cout << "B-\n";
                break;
            case 6:
                cout << "C+\n";
                break;
            case 7:
                cout << "C0\n";
                break;
            case 8:
                cout << "C-\n";
                break;
            case 9: 
                cout << "D0\n";
                break;
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}