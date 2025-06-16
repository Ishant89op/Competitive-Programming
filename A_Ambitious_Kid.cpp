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

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i: A) cin >> i;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, abs(A[i]));
    }
    cout << ans << endl;
    return 0;
}