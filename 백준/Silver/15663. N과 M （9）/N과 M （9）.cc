#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<vector<int>> s;
vector<int> check(10001);

void permutation(vector<int>& arr, vector<int>& perm, int depth)
{
    if (depth == perm.size())
    {
        s.insert(perm);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            perm[depth] = arr[i];
            permutation(arr, perm, depth + 1);
            check[i] = false;
        }
    }
}

int main()
{
    int n, r;
    cin >> n >> r;

    vector<int> v;
    vector<int> perm(r);

    for (int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    permutation(v, perm, 0);

    for (auto arr : s)
    {
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
}