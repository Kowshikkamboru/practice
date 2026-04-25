#include <stdio.h>
#include <stdlib.h>

// Structure to track each food's current value and decay
typedef struct {
    long long current_val;
    int id;
    int times_eaten;
} Food;

// Helper function to swap two items in the heap
void swap(Food *a, Food *b) {
    Food temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the Max-Heap property
void heapify(Food arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].current_val > arr[largest].current_val) largest = left;
    if (right < n && arr[right].current_val > arr[largest].current_val) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    int n;
    long long m;

    // --- INPUT PROMPTS ---
    printf("Enter number of food types (N) and max meals (M):\n");
    scanf("%d %lld", &n, &m);

    long long v[n], d[n];
    printf("Enter initial taste points (v) for %d types:\n", n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
    
    printf("Enter decay values (d) for %d types:\n", n);
    for (int i = 0; i < n; i++) scanf("%lld", &d[i]);

    // Initialize Heap
    Food *heap = (Food *)malloc(n * sizeof(Food));
    for (int i = 0; i < n; i++) {
        heap[i] = (Food){v[i], i, 1};
    }

    // Build the initial Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) heapify(heap, n, i);

    long long total_taste = 0;
    // Process M meals greedily
    for (long long i = 0; i < m; i++) {
        if (heap[0].current_val <= 0) break; // Stop if no tasty food remains

        total_taste += heap[0].current_val;

        // Calculate the next value: v[i] - d[i] * (times_eaten)
        heap[0].current_val = v[heap[0].id] - (d[heap[0].id] * heap[0].times_eaten);
        heap[0].times_eaten++;

        // Re-heapify to find the next best meal
        heapify(heap, n, 0);
    }

    // --- LABELED OUTPUT ---
    printf("\n[RESULT] Maximum Taste Points: %lld\n", total_taste);

    free(heap);
    return 0;
}