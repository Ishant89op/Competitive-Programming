//  B - Fibonacci Reversed

#include<bits/stdc++.h>

using namespace std;

long long reverse(long long x) {
    long long rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    long long a1 = x, a2 = y;
    for (int i = 3; i <= 10; i++) {
        long long s = a1 + a2;
        long long a3 = reverse(s);
        a1 = a2;
        a2 = a3;
    }

    cout << a2 << "\n";
    return 0;
}
