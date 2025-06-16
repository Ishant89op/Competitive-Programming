#include <bits/stdc++.h>
using namespace std;

int countValidSegments(const vector<int>& a, int x) {
    unordered_map<int, int> freq;
    int count = 0;
    int curr = 0;

    for (int i = 0; i < a.size(); ++i) {
        freq[a[i]]++;
        if (freq.size() >= x) {
            bool valid = true;
            for (int j = 0; j < x; ++j) {
                if (freq.find(j) == freq.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                count++;
                freq.clear();
            }
        }
    }
    return count;
}

int solve(const vector<int>& a, int k) {
    int low = 0, high = a.size(), ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = countValidSegments(a, mid);
        if (cnt >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(a, k) << "\n";
    }
    return 0;
}
