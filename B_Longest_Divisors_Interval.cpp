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

    int t;
    cin >> t;
    while(t--) {
        long long n; cin >> n;
        if(n&1) {
            cout << 1 << "\n";
            continue;
        }
        long long small = 1;
        while(1) {
            if(n%small != 0) break;
            small++;
        }
        cout << small-1 << "\n";
    }
    return 0;
}