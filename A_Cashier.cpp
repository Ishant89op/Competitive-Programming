#include <bits/stdc++.h>
using namespace std;

long long maximumBreaks(long long n, long long l, long long a, vector<vector<long long>>& con) {
    if(n==0) return l/a;
    sort(con.begin(), con.end());
    int t_c = con[0][0], t_l = con[0][0]+con[0][1];
    long long breaks = 0;
    breaks += t_c/a;
    for(int i = 1; i < n; i++) {
        t_c = con[i][0]; 
        breaks += (t_c-t_l)/a;
        t_l = con[i][0]+con[i][1];
    }
    breaks += (l-t_l)/a;
    return breaks;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, l, a;
    cin >> n >> l >> a;
    vector<vector<long long>> consumers(n, vector<long long>(2, -1));
    for(int i = 0; i < n; i++) for(int j = 0; j < 2; j++) cin >> consumers[i][j]; 
    cout << maximumBreaks(n, l, a, consumers) << endl;
    return 0;
}