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

    int test;
    cin >> test;
    while(test--) {
        long long a, b;
        cin >> a >> b;
        if(a==b) {
            cout << "0 0\n";
            continue;
        }
        long long ans = abs(a-b);
        long long moves = min(a%ans, ans - a%ans);
        cout << ans << " " << moves << "\n";
    }
    return 0;
}