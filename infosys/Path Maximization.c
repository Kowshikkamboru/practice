#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int layer;
    long long val;
    int original_id;
} Node;

// Sort nodes by layer to ensure non-decreasing processing
int layer_sort(const void* a, const void* b) {
    return ((Node*)a)->layer - ((Node*)b)->layer;
}

int main() {
    int n, m, k;

    // --- INPUT PROMPTS ---
    printf("Enter N (nodes), M (edges), and K (max layer):\n");
    scanf("%d %d %d", &n, &m, &k);

    Node nodes[n];
    int layers[n];
    long long values[n];
    for (int i = 0; i < n; i++) {
        printf("Node %d: Enter [layer] [value]: ", i);
        scanf("%d %lld", &nodes[i].layer, &nodes[i].val);
        nodes[i].original_id = i;
        layers[i] = nodes[i].layer;
        values[i] = nodes[i].val;
    }

    int u_edge[m], v_edge[m];
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) scanf("%d %d", &u_edge[i], &v_edge[i]);

    // Step 1: Sort nodes by layer
    qsort(nodes, n, sizeof(Node), layer_sort);

    long long dp[n];
    for (int i = 0; i < n; i++) dp[i] = -2e18; // Default very low

    long long max_final = 0;

    // Step 2: DP transition
    for (int i = 0; i < n; i++) {
        int u = nodes[i].original_id;
        dp[u] = values[u]; // Base case: Path starts at node u

        for (int j = 0; j < m; j++) {
            int prev = -1;
            if (u_edge[j] == u) prev = v_edge[j];
            else if (v_edge[j] == u) prev = u_edge[j];

            if (prev != -1) {
                // Constraint: Must come from a node with <= layer
                if (layers[prev] <= layers[u] && dp[prev] != -2e18) {
                    long long diff = layers[u] - layers[prev];
                    long long penalty = diff * diff;
                    long long current_score = dp[prev] + values[u] - penalty;
                    if (current_score > dp[u]) dp[u] = current_score;
                }
            }
        }
        if (dp[u] > max_final) max_final = dp[u];
    }

    // --- LABELED OUTPUT ---
    printf("\n[RESULT] Maximum Path Score: %lld\n", max_final);

    return 0;
}