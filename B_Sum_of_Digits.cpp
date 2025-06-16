#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

long long sumOfDigits(string& s) {
    long long sum = 0;
    for(int i = 0; i < s.length(); i++) {
        sum += s[i]-'0';
    }
    return sum;
}

int main() {
    fastIO();

    string n;
    cin >> n;
    long long ans = 0;
    long long sum = sumOfDigits(n);
    if(n.length() < 2) {
        cout << "0" << endl;
        return 0;
    } else {
        ans++;
        while(sum >= 10) {
            ans++;
            n = to_string(sum);
            sum = sumOfDigits(n);
        }
    }
    cout << ans << endl;
    return 0;
}