//  A - Misdelivery

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& i : v) cin >> i;
    int x;
    string y;
    cin >> x >> y;
    if (v[x-1] == y)
    {
        cout << "Yes" << endl;
    } else
    {
        cout << "No" << endl;
    }
    return 0;
}
