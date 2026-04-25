#include <stdio.h>
#include <stdlib.h>

// Comparison for sorting: Smallest to Largest
int sort_asc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
// Comparison for sorting: Largest to Smallest
int sort_desc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

int main() {
    int n, k;

    // --- INPUT PROMPTS ---
    printf("Enter array size (N) and max swaps (K):\n");
    scanf("%d %d", &n, &k);
    
    int a[n];
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long long global_max = -2e18; // Initialize with a very small value

    // Check every possible subarray window [i, j]
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int inside[500], outside[500];
            int in_sz = 0, out_sz = 0;
            long long current_sum = 0;

            // Step 1: Split array into inside and outside current window
            for (int x = 0; x < n; x++) {
                if (x >= i && x <= j) {
                    inside[in_sz++] = a[x];
                    current_sum += a[x];
                } else {
                    outside[out_sz++] = a[x];
                }
            }

            // Step 2: Sort to find best potential swap candidates
            qsort(inside, in_sz, sizeof(int), sort_asc);
            qsort(outside, out_sz, sizeof(int), sort_desc);

            // Step 3: Perform up to K swaps if beneficial
            int swaps_to_do = (k < in_sz) ? k : in_sz;
            if (out_sz < swaps_to_do) swaps_to_do = out_sz;

            for (int s = 0; s < swaps_to_do; s++) {
                if (outside[s] > inside[s]) {
                    current_sum += (outside[s] - inside[s]);
                } else break;
            }

            if (current_sum > global_max) global_max = current_sum;
        }
    }

    // --- LABELED OUTPUT ---
    printf("\n[RESULT] Maximum Possible MSS after Swaps: %lld\n", global_max);

    return 0;
}