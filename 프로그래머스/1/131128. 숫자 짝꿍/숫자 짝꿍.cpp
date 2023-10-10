#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> x;
    vector<char> y;
    vector<char> v;
    for(int i = 0; i < X.length(); i++) {
        x.push_back(X[i]);
    }
    for(int j = 0; j < Y.length(); j++) {
        y.push_back(Y[j]);
    }
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());
    
    while(true) {
        int j = 0;
        for(int i = 0; i < x.size(); i++) {
            if(j < y.size()) {
            if(x[i] > y[j]) continue;
            else if(x[i] < y[j]) {
                j++;
                i--;
            }
            else v.push_back(y[j++]);
            }
        }
        break;
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    
    if(answer.length() <= 0) return "-1";
    else {
        if(answer[0] == '0') return "0";
        else return answer;
    }
}