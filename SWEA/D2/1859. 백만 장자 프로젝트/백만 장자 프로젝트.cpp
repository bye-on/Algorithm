#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        long long n;
        cin >> n;

        vector<int> v;
        for (long long i = 0; i < n; i++)
        {
            long long input;
            cin >> input;
            v.push_back(input);
        }

        long long maxnum = v[v.size() - 1];
        long long result = 0;
        for (long long i = v.size() - 1; i >= 0; i--)
        {
            long long remain = maxnum - v[i];
            if (remain > 0)
                result += remain;
            else
                maxnum = v[i];
        }
        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}