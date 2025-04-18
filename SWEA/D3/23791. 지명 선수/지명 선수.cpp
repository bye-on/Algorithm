#include<iostream>
#include<queue>
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

        queue<int> A;
        queue<int> B;
        vector<bool> check(n + 1);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            A.push(a);
        }
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            B.push(b);
        }

        vector<char> str(n + 1);
        bool Aturn = true; int cnt = 0;
        while (true)
        {
            if (cnt == n)
                break;

            if (Aturn)
            {
                while (true)
                {
                    int top = A.front();
                    A.pop();
                    if (!check[top])
                    {
                        check[top] = true;
                        str[top] = 'A';
                        Aturn = false;
                        cnt++;
                        break;
                    }
                    if (A.empty())
                    {
                        Aturn = false;
                        break;
                    }
                }
            }
            else
            {
                while (true)
                {
                    int top = B.front();
                    B.pop();
                    if (!check[top])
                    {
                        check[top] = true;
                        str[top] = 'B';
                        Aturn = true;
                        cnt++;
                        break;
                    }
                    if (B.empty())
                    {
                        Aturn = true;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
            cout << str[i];
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}