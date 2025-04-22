#include<iostream>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin>>T;
    
    map<string, int> m;
    m.insert({"red", 0});    m.insert({"orange", 1});
    m.insert({"yellow", 2});    m.insert({"green", 3});
    m.insert({"blue", 4});    m.insert({"purple", 5});

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string c1, c2;
        cin >> c1 >> c2;
		
        int num = abs(m[c1] - m[c2]) % 4;
        if(num == 0)
            cout << "E\n";
        else if(num == 1)
            cout << "A\n";
        else if(num == 3)
            cout << "C\n";
        else 
            cout << "X\n";
	}
	return 0; //정상종료시 반드시 0을 리턴해야합니다.
}