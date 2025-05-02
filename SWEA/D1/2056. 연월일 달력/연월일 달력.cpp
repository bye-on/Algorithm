#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str;
        cin >> str;
        
        cout << "#" << test_case << " ";
        
        string year = str.substr(0, 4);
        string month = str.substr(4, 2);
        string day = str.substr(6, 2);

        int m = stoi(month);
        int d = stoi(day);
        if(m < 1 || m > 12)
            cout << "-1\n";
        if(d < 1)
            cout << "-1\n";
        
        switch(m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                {
                    if( d > 31)
                        cout << "-1\n";
                    else
                        cout << year << "/" << month << "/" << day << '\n';
                    
                    break;
                }
           	case 4:
            case 6:
            case 9:
            case 11:
                {
                    if( d > 30)
                        cout << "-1\n";
                    else
                        cout << year << "/" << month << "/" << day << '\n';
                    
                    break;
                }
            case 2:
                {
                    if( d > 28)
                        cout << "-1\n";
                    else
                        cout << year << "/" << month << "/" << day << '\n';
                    
                    break;
                }
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}