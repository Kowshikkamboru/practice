#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparison for sorting costs
int cmp(const void* a, const void* b) {
    long long v1 = *(long long*)a;
    long long v2 = *(long long*)b;
    return (v1 > v2) - (v1 < v2);
}

int main() {
    int n;

    // --- INPUT PROMPTS ---
    printf("Enter number of locks (N):\n");
    scanf("%d", &n);
    
    long long L[n];
    printf("Enter %d lock values:\n", n);
    for (int i = 0; i < n; i++) scanf("%lld", &L[i]);

    long long evens[40000], odds[40000];
    int e_cnt = 0, o_cnt = 0;

    // Step 1: Enumerate all valid j < i pairings
    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
            if (L[j] == L[i]) continue;
            long long cost = llabs(L[j] - L[i]);
            if (cost % 2 == 0) evens[e_cnt++] = cost;
            else odds[o_cnt++] = cost;
        }
    }

    // Step 2: Sort costs to find the minimums
    qsort(evens, e_cnt, sizeof(long long), cmp);
    qsort(odds, o_cnt, sizeof(long long), cmp);

    long long result = -1;

    // Option A: Single smallest even cost
    if (e_cnt > 0) result = evens[0];

    // Option B: Smallest even + Smallest odd (if even >= odd is required for multiple)
    if (e_cnt > 0 && o_cnt > 0) {
        long long combined = evens[0] + odds[0];
        if (result == -1 || combined < result) result = combined;
    }

    // --- LABELED OUTPUT ---
    if (result == -1) printf("\n[RESULT] No valid assignment set found: -1\n");
    else printf("\n[RESULT] Minimum Effective Value Sum: %lld\n", result);

    return 0;
}