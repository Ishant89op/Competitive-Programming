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
        int n;
        cin >> n;
        int a = 1, b = -1;
        for (int g = 2; g * g <= n; ++g) {
            if (n % g == 0) {
                a = n / g;
                break;
            }
        }
        b = n - a;
        cout << a << " " << b << "\n";
    }
    return 0;
}