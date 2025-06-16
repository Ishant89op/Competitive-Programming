#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int mx = 10000007;
    vector<bool> is_prime(mx + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= mx; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= mx; j += i) {
                is_prime[j] = false;
            }
        }
    }

    while (T--) {
        int n;
        cin >> n;

        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            if (is_prime[i]) {
                ans+= ((n)/i);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}