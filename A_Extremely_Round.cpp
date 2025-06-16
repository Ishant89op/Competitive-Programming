#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

int dp[1000000] = {0};
bool rare(int x) {
    int zero = 0;
    string s = to_string(x);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') zero++;
    }
    return zero == s.size()-1;
}
void calc() {
    for(int i = 0; i <= 10; i++) dp[i] = i;
    for(int i = 11; i <= 999999; i++) {
        dp[i] = dp[i-1];
        if(rare(i)) dp[i]++;
    }
}
int main() {
    fastIO();
    calc();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}