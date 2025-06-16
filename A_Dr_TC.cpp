#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

int main() {
    fastIO();

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ones = count(s.begin(), s.end(), '1');
        int zero = n-ones;
        if(ones == 0) {
            cout << n << "\n";
            continue;
        } else if(zero == 0) {
            cout << n*(n-1) << "\n";
            continue;
        } else {
            int ans = zero+((ones-1)*ones)+(zero*ones);
            cout << ans << "\n";
        }
    }
    return 0;
}