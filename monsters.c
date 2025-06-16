#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    long long first;
    int second;
} pii;

int cmp(const void* a, const void* b) {
    pii* p1 = (pii*)a;
    pii* p2 = (pii*)b;

    if (p1->first != p2->first)
        return (p2->first - p1->first > 0) ? 1 : -1; // descending
    return p1->second - p2->second; // ascending index
}

void solve() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);

    pii A[MAXN];

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &A[i].first);
        A[i].second = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        if (A[i].first > k) {
            A[i].first %= k;
        }
    }

    qsort(A, n, sizeof(pii), cmp);

    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i].second);
    }
    printf("\n");
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        solve();
    }

    return 0;
}
