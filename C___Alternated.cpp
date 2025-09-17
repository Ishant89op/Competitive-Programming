//  C - Alternated

#include<bits/stdc++.h>

using namespace std;

signed main()
{
    long long n;
    string s;
    cin >> n >> s;
    long long N = 2*n;
    // string tar1, tar2;
    // for (int i = 0; i < N; i++)
    // {
    //     if (i&1)
    //     {
    //         tar1 += "A";
    //         tar2 += "B";
    //     }
    //     else
    //     {
    //         tar1 += "B";
    //         tar2 += "A";
    //     }
    // }
    //
    // long long c1 = 0, c2 = 0;
    // for (int i = 0; i < N; i++)
    // {
    //     if (s[i] != tar1[i])
    //     {
    //         c1++;
    //     }
    //     if (s[i] != tar2[i])
    //     {
    //         c2++;
    //     }
    // }
    //
    // cout << min(c1, c2) << "\n";

    vector<int> A;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') A.push_back(i);
    }

    long long c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        c1 += abs(A[i] - 2*i);
        c2 += abs(A[i] - ((2*i)+1));
    }

    cout << min(c1, c2) << "\n";

    return 0;
}
