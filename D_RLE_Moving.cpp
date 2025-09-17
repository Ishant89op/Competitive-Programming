//  D - RLE Moving

#include<bits/stdc++.h>

using namespace std;

// void U(long long& x, long long times) { x-=times; }
// void D(long long& x, long long times) { x+=times; }
// void L(long long& y, long long times) { y-=times; }
// void R(long long& y, long long times) { y+=times; }

pair<int,int> dirVec(char d) {
    if (d == 'U') return {-1, 0};
    if (d == 'D') return {1, 0};
    if (d == 'L') return {0, -1};
    if (d == 'R') return {0, 1};
    return {0, 0};
}

long long solveSegment(long long xt, long long yt, long long xa, long long ya, char Dt, char Da, long long len) {
    auto [dx_t, dy_t] = dirVec(Dt);
    auto [dx_a, dy_a] = dirVec(Da);

    long long dr = xt - xa;
    long long dc = yt - ya;
    long long vr = dx_t - dx_a;
    long long vc = dy_t - dy_a;

    if (vr == 0 && vc == 0) { // same relative row and column velocity
        if (dr == 0 && dc == 0) return len; // standing on the same block before movement
        return 0; // otherwise
    }

    long long krv = -1, kcv = -1;

    // same row velocity
    if (vr == 0) {
        if (dr != 0) return 0; // same row velocity but not the same row, not possible
    } else {
        // dr + k * vr = 0
        if ((-dr) % vr == 0) krv = (-dr) / vr; 
        else return 0;
    }

    // same column velocity
    if (vc == 0) {
        if (dc != 0) return 0; // same col velocity but not the same col, not possible
    } else {
        // dc + k * vc = 0
        if ((-dc) % vc == 0) kcv = (-dc) / vc; // if divisible then k col are valid
        else return 0;
    }

    long long k = -1;
    if (krv != -1 && kcv != -1) {
        // if both equations gives some value then they must be equal
        // dr + k * vr = dc + k * vc
        if (krv != kcv) return 0;
        k = krv;
    } else if (krv != -1) {
        k = krv;
    } else if (kcv != -1) {
        k = kcv;
    } else {
        return 0;
    }

    // they will meet after at least one move and before "len" otherwise no.
    if (k >= 1 && k <= len) return 1;
    return 0;
}

int main()
{
    long long rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;
    long long n, m, l;
    cin >> n >> m >> l;
    vector<pair<char, long long>> sv(m), tv(l);
    for (int i = 0; i < m; i++)
    {
        cin >> sv[i].first >> sv[i].second;
    }
    for (int i = 0; i < l; i++)
    {
        cin >> tv[i].first >> tv[i].second;
    }
    long long ans = 0;
    // long long j = 0, k = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     while (j < m && sv[j].second == 0) j++;
    //     while (k < l && tv[k].second == 0) k++;
    //     if (j < m)
    //     {
    //         if (sv[j].first == 'U')
    //         {
    //             U(rt);
    //             sv[j].second--;
    //         } else if (sv[j].first == 'D')
    //         {
    //             D(rt);
    //             sv[j].second--;
    //         } else if (sv[j].first == 'L')
    //         {
    //             L(ct);
    //             sv[j].second--;
    //         } else if (sv[j].first == 'R')
    //         {
    //             R(ct);
    //             sv[j].second--;
    //         }
    //     }

    //     if (k < l)
    //     {
    //         if (tv[k].first == 'U')
    //         {
    //             U(ra);
    //             tv[k].second--;
    //         }  else if (tv[k].first == 'D')
    //         {
    //             D(ra);
    //             tv[k].second--;
    //         }  else if (tv[k].first == 'L')
    //         {
    //             L(ca);
    //             tv[k].second--;
    //         }  else if (tv[k].first == 'R')
    //         {
    //             R(ca); 
    //             tv[k].second--;
    //         }
    //     }
    //     if (rt == ra && ct == ca) ans++;
    // }
    long long i = 0, j = 0;
    long long res = sv[0].second, ret = tv[0].second;

    while (i < m && j < l) {
        long long len = min(res, ret);

        ans += solveSegment(rt, ct, ra, ca, sv[i].first, tv[j].first, len);

        auto [dx_t, dy_t] = dirVec(sv[i].first);
        auto [dx_a, dy_a] = dirVec(tv[j].first);
        rt += dx_t * len;
        ct += dy_t * len;
        ra += dx_a * len;
        ca += dy_a * len;

        res -= len;
        ret -= len;
        if (res == 0 && ++i < m) res = sv[i].second;
        if (ret == 0 && ++j < l) ret = tv[j].second;
    }

    cout << ans << "\n";
    return 0;
}