#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, p, k;
    cin >> n >> p >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll xor_values = (a[i] ^ a[j]);
            ll ai_squared = ((a[i] % p) * (a[i] % p)) % p;
            ll aj_squared = ((a[j] % p) * (a[j] % p)) % p;
            ll xor_squares = (ai_squared ^ aj_squared);
            ll product = (xor_values * xor_squares) % p;
            
            if (product == k) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}