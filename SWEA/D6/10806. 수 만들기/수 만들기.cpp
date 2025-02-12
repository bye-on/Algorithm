#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            v.push_back(input);
        }
        int k; 
        cin >> k;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, k });
        while (pq.top().second != 0)
        {
            int cnt = pq.top().first;
            int remain = pq.top().second;
            pq.pop();

            pq.push({ cnt + remain, 0 });

            for (int i = 0; i < n; i++)
            {
                pq.push({ cnt + remain % v[i], remain / v[i] });
            }
        }

        cout << "#" << test_case << " ";
        cout << pq.top().first << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}